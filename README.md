# ChatGPT Custom Mod

Un mod personalizado para [Geode](https://geode-sdk.org/) que añade un botón informativo al menú principal de Geometry Dash.

## Funciones

- Añade un botón nuevo al `bottom-menu` de `MenuLayer`.
- Muestra un popup de bienvenida opcional al entrar al menú principal.
- Incluye ajustes configurables desde Geode:
  - `Mostrar bienvenida`
  - `Texto del botón`

## Requisitos

- Geometry Dash compatible con Geode.
- Geode SDK instalado.
- Variable de entorno `GEODE_SDK` apuntando al SDK.
- CMake 3.21 o superior.
- Compilador con soporte C++20.

## Compilación

```bash
cmake -S . -B build
cmake --build build --config Release
```

## Estructura

```text
.
├── CMakeLists.txt
├── mod.json
├── README.md
└── src
    └── main.cpp
```

## Personalización

Cambia los ajustes en el menú de configuración de Geode para desactivar el popup inicial o modificar el texto del botón.
