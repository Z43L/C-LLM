import os
import json

# Directorio que contiene los archivos markdown
DOCU_ROOT = 'docu'

# Función para limpiar y formatear el nombre para la navegación
def format_name(name):
    # Quita la extensión .md y los números iniciales (ej: "1.2-")
    name = name.replace('.md', '')
    parts = name.split('-')
    if len(parts) > 1 and parts[0].replace('.', '').isdigit():
        return '-'.join(parts[1:]).strip().capitalize()
    return name.replace('_', ' ').capitalize()

# Función recursiva para construir la estructura de navegación
def build_nav_structure(path):
    structure = []
    items = sorted(os.listdir(path)) # Ordena para mantener la consistencia
    for item in items:
        item_path = os.path.join(path, item)
        if os.path.isdir(item_path):
            structure.append({
                "name": format_name(item),
                "type": "category",
                "children": build_nav_structure(item_path)
            })
        elif item.endswith('.md'):
            # Usa una barra inclinada para las rutas web
            web_path = item_path.replace(os.sep, '/')
            structure.append({
                "name": format_name(item),
                "type": "file",
                "path": web_path
            })
    return structure

# Función para construir el sistema de archivos virtual
def build_virtual_filesystem(path):
    fs = {}
    for root, _, files in os.walk(path):
        for file in files:
            if file.endswith('.md'):
                file_path = os.path.join(root, file)
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    # Usa una barra inclinada para las rutas web
                    web_path = file_path.replace(os.sep, '/')
                    fs[web_path] = content
    return fs

# --- MAIN EXECUTION ---
if __name__ == "__main__":
    if not os.path.isdir(DOCU_ROOT):
        print(f"Error: El directorio '{DOCU_ROOT}' no existe.")
        print("Por favor, crea una carpeta llamada 'docu' y coloca tus archivos .md dentro.")
    else:
        virtual_fs = build_virtual_filesystem(DOCU_ROOT)
        nav_structure = build_nav_structure(DOCU_ROOT)

        # Imprime el resultado en formato JavaScript
        print("// --- Contenido generado automáticamente por generador.py ---")
        print("// --- Reemplaza el contenido antiguo en tu index.html con esto ---")
        print("\nconst virtualFileSystem = " + json.dumps(virtual_fs, indent=4, ensure_ascii=False) + ";")
        print("\nconst navigationStructure = " + json.dumps(nav_structure, indent=4, ensure_ascii=False) + ";")
        print("\n// --- Fin del contenido generado ---")
