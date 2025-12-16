import os
import json

# Configuration
DATA_FILE = 'data.json'
FOLDERS_TO_SCAN = {
    'Syllabus': 'syllabus',
    'Assignments': 'assignments',
    'ebooks': 'ebooks',
    'ExamPapers': 'exampapers'
    # Notes_Programs handled separately due to nested units
}

def load_json():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r') as f:
            return json.load(f)
    return {"syllabus": [], "notes_programs": {}, "assignments": [], "ebooks": [], "exampapers": []}

def save_json(data):
    with open(DATA_FILE, 'w') as f:
        json.dump(data, f, indent=2)

def entry_exists(file_path, current_list):
    """Checks if a file path already exists in the list of dicts."""
    for entry in current_list:
        if isinstance(entry, dict) and entry.get('path') == file_path:
            return True
        if isinstance(entry, str) and entry == file_path:
            return True
    return False

def update_simple_folders(data):
    """Updates simple array based categories (Syllabus, etc.)"""
    for folder, json_key in FOLDERS_TO_SCAN.items():
        if not os.path.exists(folder):
            continue

        current_list = data.get(json_key, [])

        # Scan directory
        for filename in os.listdir(folder):
            # Skip system files
            if filename.startswith('.'): continue

            file_path = f"{folder}/{filename}"

            if not entry_exists(file_path, current_list):
                print(f"Adding new file: {file_path}")
                # Add with hidden=true as requested
                current_list.append({
                    "path": file_path,
                    "hidden": True
                })

        data[json_key] = current_list

def update_notes_programs(data):
    """Updates the nested Notes_Programs category"""
    base_folder = "Notes_Programs"
    if not os.path.exists(base_folder):
        return

    notes_data = data.get("notes_programs", {})

    # Scan subdirectories (UNIT-1, UNIT-2, etc.)
    for unit_folder in os.listdir(base_folder):
        unit_path = os.path.join(base_folder, unit_folder)

        if os.path.isdir(unit_path):
            current_unit_list = notes_data.get(unit_folder, [])

            for filename in os.listdir(unit_path):
                if filename.startswith('.'): continue

                file_path = f"{base_folder}/{unit_folder}/{filename}"

                if not entry_exists(file_path, current_unit_list):
                    print(f"Adding new Note/Program: {file_path}")
                    current_unit_list.append({
                        "path": file_path,
                        "hidden": True
                    })

            notes_data[unit_folder] = current_unit_list

    data["notes_programs"] = notes_data

if __name__ == "__main__":
    print("Scanning repository for new files...")
    data = load_json()
    update_simple_folders(data)
    update_notes_programs(data)
    save_json(data)
    print("data.json updated.") 
