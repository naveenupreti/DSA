import os
import json

# Configuration
DATA_FILE = 'data.json'
FOLDERS_TO_SCAN = {
    'Syllabus': 'syllabus',
    'Assignments': 'assignments',
    'ebooks': 'ebooks',
    'ExamPapers': 'exampapers'
}

def load_json():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r') as f:
            return json.load(f)
    return {"syllabus": [], "notes_programs": {}, "assignments": [], "ebooks": [], "exampapers": []}

def save_json(data):
    with open(DATA_FILE, 'w') as f:
        json.dump(data, f, indent=2)

def update_simple_folders(data):
    """Syncs simple folder categories (Add & Delete)"""
    for folder, json_key in FOLDERS_TO_SCAN.items():
        if not os.path.exists(folder):
            continue

        # 1. Get current files on disk
        files_on_disk = [f"{folder}/{fn}" for fn in os.listdir(folder) if not fn.startswith('.')]
        
        # 2. Filter existing JSON list: Keep only if file still exists
        current_list = data.get(json_key, [])
        updated_list = [entry for entry in current_list if entry.get('path') in files_on_disk]

        # 3. Add new files found on disk
        existing_paths = {entry.get('path') for entry in updated_list}
        for file_path in files_on_disk:
            if file_path not in existing_paths:
                print(f"Adding new file: {file_path}")
                updated_list.append({"path": file_path, "hidden": False})

        data[json_key] = updated_list

def update_notes_programs(data):
    """Syncs nested Notes_Programs (Add & Delete)"""
    base_folder = "Notes_Programs"
    if not os.path.exists(base_folder):
        return

    notes_data = data.get("notes_programs", {})
    
    # Scan existing units in folder
    units_on_disk = [d for d in os.listdir(base_folder) if os.path.isdir(os.path.join(base_folder, d))]

    # Clean up units in JSON that no longer exist on disk
    notes_data = {unit: files for unit, files in notes_data.items() if unit in units_on_disk}

    for unit_folder in units_on_disk:
        unit_path = os.path.join(base_folder, unit_folder)
        files_on_disk = [f"Notes_Programs/{unit_folder}/{fn}" for fn in os.listdir(unit_path) if not fn.startswith('.')]
        
        current_unit_list = notes_data.get(unit_folder, [])
        
        # Keep only files still on disk
        updated_unit_list = [entry for entry in current_unit_list if entry.get('path') in files_on_disk]
        
        # Add new files
        existing_paths = {entry.get('path') for entry in updated_unit_list}
        for file_path in files_on_disk:
            if file_path not in existing_paths:
                print(f"Adding new Note: {file_path}")
                updated_unit_list.append({"path": file_path, "hidden": False})
        
        notes_data[unit_folder] = updated_unit_list

    data["notes_programs"] = notes_data

if __name__ == "__main__":
    print("Syncing data.json with repository...")
    data = load_json()
    update_simple_folders(data)
    update_notes_programs(data)
    save_json(data)
    print("Sync complete.")
