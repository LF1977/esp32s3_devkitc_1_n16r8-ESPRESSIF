# ESP32‑S3‑DevKitC‑1‑N16R8 – Custom PlatformIO Projekt

Dieses Projekt verwendet eine **eigene, nicht‑offizielle Board‑Definition** für das  
**ESP32‑S3‑DevKitC‑1‑N16R8** (16 MB Flash, 8 MB PSRAM).  
Es basiert auf PlatformIO und ESP‑IDF und ist vollständig manuell konfiguriert.

## 🎯 Zweck des Projekts
- Bereitstellen eines **Custom‑Boardprofils**, das nicht in PlatformIO enthalten ist  
- Nutzung der vollen Hardware:
  - 16 MB Flash  
  - 8 MB OPI‑PSRAM  
- Eigene Partitionstabelle mit:
  - OTA0 / OTA1
  - SPIFFS
  - Coredump
- Grundlage für eigene Firmware‑Projekte mit ESP‑IDF

## 🧩 Custom Board Definition
Die Datei befindet sich in:

boards/esp32s3_devkitc_1_n16r8.json


Sie definiert u. a.:

- MCU: ESP32‑S3  
- Flash: 16 MB @ 80 MHz QIO  
- PSRAM: OPI  
- Frameworks: ESP‑IDF / Arduino  
- Extra Flags:
  - `-DBOARD_HAS_PSRAM`
  - `-DCONFIG_IDF_TARGET_ESP32S3`

## ⚙️ PlatformIO Konfiguration
`platformio.ini`:

[platformio]
boards_dir = boards

[env:esp32s3_devkitc_1_n16r8]
platform = espressif32
board = esp32s3_devkitc_1_n16r8
framework = espidf
monitor_speed = 115200

board_build.psram = true


## 📦 Partitionstabelle
`default_16MB.csv`:

Name, Type, SubType, Offset, Size, Flags

nvs,      data, nvs,     0x9000,  0x5000,
otadata,  data, ota,     0xe000,  0x2000,
app0,     app,  ota_0,   0x10000, 0x640000,
app1,     app,  ota_1,   0x650000, 0x640000,
spiffs,   data, spiffs,  0xc90000,0x360000,
coredump, data, coredump,0xFF0000,0x10000,


## 📁 Projektstruktur

/src        → main.c
/include    → Header-Dateien
/lib        → eigene Module
/boards     → esp32s3_devkitc_1_n16r8.json
default_16MB.csv → Partitionstabelle


## 🚀 Nutzung
1. Repository klonen  
2. In VSCode öffnen  
3. PlatformIO: Build & Upload  
4. Firmware läuft auf dem ESP32‑S3‑DevKitC‑1‑N16R8

## Hinweis
Dieses Projekt nutzt **keine offizielle PlatformIO‑Boarddefinition**.  
Alle Einstellungen sind vollständig manuell erstellt.

