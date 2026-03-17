[![Consultar a DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/MauricioCastro16/analisis-datos-residuos)

# Sistema de Análisis de Residuos Regionales

[![Language](https://img.shields.io/badge/language-C-orange.svg)](https://github.com/MauricioCastro16/Lab-C-2022)

Sistema completo en C para recolección, almacenamiento y análisis estadístico de datos de residuos por región en Argentina. Permite generar reportes regionales sobre porcentajes de reciclaje, montos de venta y proyecciones de sostenibilidad familiar.

## Características Principales

- Ingestión de datos manual y automática con validación de provincias argentinas
- Clasificación automática por regiones geográficas (Noroeste, Nordeste, Pampeana, Cuyo, Patagonia)
- Procesamiento mediante matriz de agregación 6x6 para análisis multidimensional
- Cálculo de porcentajes de reciclaje y montos de venta por tipo de residuo
- Proyecciones de sostenibilidad familiar basadas en aumento del reciclaje
- Sistema de alertas para capacidad de basurales por región

## Flujo

El sistema implementa una arquitectura secuencial de dos programas: `Carga de Datos.c` para ingestión y `Principal.c` para análisis. Ambos programas comparten una estructura `basura` y utilizan el archivo binario `Basura.dat` como único canal de comunicación. El programa de análisis carga todos los registros en una matriz de agregación `A[6][6]` para procesamiento eficiente de consultas estadísticas.

## Instalación y Uso

```bash
# Clonar el repositorio
git clone https://github.com/MauricioCastro16/analisis-datos-residuos.git
cd analisis-datos-residuos

# Compilar programa de carga de datos
gcc "Carga de Datos.c" -o carga_datos.exe

# Compilar programa de análisis
gcc "Principal.c" -o principal.exe

# Ejecutar carga de datos (primero)
./carga_datos.exe

# Ejecutar análisis (después)
./principal.exe
```

## Secuencia de Operación

1. Ejecutar `Carga de Datos.c` y seleccionar opción 1 para crear el archivo
2. Usar opción 2 (manual) u 3 (automático) para poblar datos
3. Ejecutar `Principal.c` para realizar análisis estadísticos
4. Seleccionar opciones 1-4 para diferentes tipos de reportes
