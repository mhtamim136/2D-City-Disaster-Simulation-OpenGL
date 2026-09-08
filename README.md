<div align="center">

# 🏙️ 2D City Disaster Simulation — OpenGL

### A modular, interactive 2D city disaster simulation built with C++ and OpenGL

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![OpenGL](https://img.shields.io/badge/OpenGL-GLUT%2FFreeGLUT-5586A4?style=for-the-badge&logo=opengl&logoColor=white)](https://www.opengl.org/)
[![IDE](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-lightgrey?style=for-the-badge)](http://www.codeblocks.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)

</div>

---

## 📌 Overview

**2D City Disaster Simulation** is a fully interactive OpenGL-based simulation developed in **C++** that renders a detailed 2D city environment and simulates six disaster scenarios in real time. The project features handcrafted graphics drawn entirely with **OpenGL primitives**, dynamic keyboard-driven controls, animated elements, day/evening/night lighting modes, and a modular codebase split across dedicated scene and UI modules.

📄 [**Full Project Report (PDF)**](City%20Disaster%20Simulation.pdf) &nbsp;|&nbsp; 📝 [**Full Project Report (DOCX)**](City%20Disaster%20Simulation.docx)

---

## 📋 Table of Contents

- [Scenes](#-scenes)
- [Screenshots](#-screenshots)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Project Structure](#-project-structure)
- [Setup & Build](#-setup--build)
- [Keyboard Controls](#-keyboard-controls)
- [Team](#-team)
- [Author](#-author)

---

## 🎬 Scenes

The simulation contains **6 interactive scenes** navigable via keyboard:

| # | Scene | Description |
|---|---|---|
| 0 | **Normal City** | Default city view with animated cars, clouds, birds, and people. Supports Day / Evening / Night lighting modes |
| 1 | **Earthquake** | Buildings shake and crack with seismic tremor animation |
| 2 | **Fire** | Buildings catch fire with animated flames; fire hose response simulation |
| 3 | **Flood** | Rising water levels flood the city streets; animated boat rescue |
| 4 | **Storm** | Heavy rain, lightning, and strong wind effects |
| 5 | **Road Accident** | Vehicle collision scene with ambulance response animation |

---

## 📸 Screenshots

### Intro & City Views

| Intro Screen | Normal City | Evening Mode | Night Mode |
|---|---|---|---|
| ![Intro](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Intro.png) | ![Normal City](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Normal%20City.png) | ![Evening Mode](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Evening%20mode.png) | ![Night Mode](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Night%20Mode.png) |

### Disaster Scenes

| Earthquake | Fire | Flood |
|---|---|---|
| ![Earthquake](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Earthquake.png) | ![Fire](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Fire.png) | ![Flood](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Flood.png) |

| Storm | Road Accident | Ending |
|---|---|---|
| ![Storm](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Storm.png) | ![Road Accident](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Road%20Accident.png) | ![Ending](https://raw.githubusercontent.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/main/Screenshot/Ending.png) |

---

## ✨ Features

- 🎮 **6 Interactive Scenes** — Normal City, Earthquake, Fire, Flood, Storm, Road Accident
- 🌅 **3 Lighting Modes** — Day, Evening (sunset), and Night mode for the Normal City scene
- 🚗 **Real-time Animations** — Moving cars, birds, boats, clouds, ambulances, and people
- 🔥 **Disaster Effects** — Flames, rising floodwater, earthquake tremors, storm rain/lightning
- ⌨️ **Full Keyboard Controls** — Scene switching, zoom, pause, lighting toggle, and more
- 🏗️ **Handcrafted Graphics** — Entirely drawn with OpenGL 2D primitives (no textures)
- 🪟 **Intro & Ending Screens** — Full animated intro splash and simulation end screen
- 🧩 **Modular Architecture** — Code split into `scenes/`, `city/`, `core/`, and `ui/` modules
- 🪟 **Zoom Support** — Real-time zoom in/out capability
- ⏸️ **Pause/Resume** — Freeze and unfreeze animation at any time

---

## 🛠️ Tech Stack

| Technology | Role |
|---|---|
| **C++** | Core programming language |
| **OpenGL (GL/GLUT)** | 2D rendering pipeline |
| **FreeGLUT** | Window management, keyboard/mouse input, animation loop |
| **Code::Blocks** | IDE and project build system (`.cbp` project file) |
| **`build.bat`** | Windows batch script for command-line compilation |

---

## 📁 Project Structure

```
2D-City-Disaster-Simulation-OpenGL/
│
├── Screenshot/                     # Scene screenshots (10 images)
│   ├── Intro.png
│   ├── Normal City.png
│   ├── Evening mode.png
│   ├── Night Mode.png
│   ├── Earthquake.png
│   ├── Fire.png
│   ├── Flood.png
│   ├── Storm.png
│   ├── Road Accident.png
│   └── Ending.png
│
├── freeglut/                       # FreeGLUT library (headers, binaries, libs)
│   ├── bin/
│   ├── include/
│   └── lib/
│
├── openglportable/                 # Main source code
│   ├── main.cpp                    # Entry point — scene controller, keyboard handler
│   │
│   ├── core/                       # Core rendering utilities
│   │   ├── shapes.h                # Low-level shape drawing primitives
│   │   └── algorithms.h            # Geometric algorithms
│   │
│   ├── city/                       # City environment components
│   │   ├── environment.h           # Sky, ground, road rendering
│   │   ├── buildings.h             # Buildings and structures
│   │   ├── props.h                 # Trees, lamp posts, misc city props
│   │   ├── vehicles.h              # Cars, ambulance, boat
│   │   └── people.h                # Animated pedestrian figures
│   │
│   ├── scenes/                     # Disaster scene modules
│   │   ├── earthquake.h            # Earthquake tremor effect
│   │   ├── fire.h                  # Fire + fire hose animation
│   │   ├── flood.h                 # Rising water + boat rescue
│   │   ├── storm.h                 # Rain, wind, lightning effects
│   │   └── accident.h              # Road collision + ambulance response
│   │
│   ├── ui/                         # UI overlays
│   │   ├── intro.h                 # Intro splash screen
│   │   ├── hud.h                   # Heads-up display / scene labels
│   │   ├── night.h                 # Night sky overlay (stars, moon)
│   │   ├── evening.h               # Evening sky (sunset gradient)
│   │   └── ending.h                # End screen
│   │
│   ├── build.bat                   # Windows build script
│   └── openglportable.cbp          # Code::Blocks project file
│
├── City Disaster Simulation.pdf    # Full project report (PDF)
└── City Disaster Simulation.docx   # Full project report (DOCX)
```

---

## ⚙️ Setup & Build

### Prerequisites

- Windows OS
- [Code::Blocks](http://www.codeblocks.org/) with MinGW compiler **or** any GCC-compatible compiler
- FreeGLUT (included in the `freeglut/` folder — no separate installation needed)

### Option 1 — Code::Blocks (Recommended)

```bash
# 1. Clone the repository
git clone https://github.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL.git

# 2. Open Code::Blocks
# File → Open → select: openglportable/openglportable.cbp

# 3. Build & Run
# Press F9 (Build and Run)
```

### Option 2 — Command Line (`build.bat`)

```bash
# Navigate to the openglportable folder
cd openglportable

# Run the build script
build.bat
```

> ⚠️ **Note:** Make sure the `freeglut/bin/` directory is accessible. The `freeglut.dll` may need to be in the same folder as the compiled executable.

---

## ⌨️ Keyboard Controls

| Key | Action |
|---|---|
| `0` | Switch to **Normal City** scene |
| `1` | Switch to **Earthquake** scene |
| `2` | Switch to **Fire** scene |
| `3` | Switch to **Flood** scene |
| `4` | Switch to **Storm** scene |
| `5` | Switch to **Road Accident** scene |
| `N` | Toggle **Night Mode** (Normal City only) |
| `E` | Toggle **Evening Mode** (Normal City only) |
| `W` | Toggle **Water / Hose** (Fire scene) |
| `P` | **Pause / Resume** animation |
| `+` | **Zoom In** |
| `-` | **Zoom Out** |
| `Space` / `Enter` | Dismiss intro / proceed |
| `ESC` | Exit the simulation |

---

## 👥 Team

This project was developed as a group assignment. Module responsibilities:

| Member | Modules |
|---|---|
| **Md. Murad Hasan** | `main.cpp`, `city/environment.h`, `city/buildings.h`, `ui/night.h` |
| **Md. Rabby Sarker Rony** | `core/algorithms.h`, `city/vehicles.h`, `scenes/fire.h` |
| **Md. Sadman Amin Bhuiyan Suny** | `core/shapes.h`, `city/people.h`, `scenes/accident.h`, `ui/ending.h` |
| **Fahmida Islam Bayan** | `city/props.h`, `scenes/storm.h`, `ui/evening.h`, `ui/intro.h` |
| **Noshin Sunzida Alam** | `scenes/earthquake.h`, `scenes/flood.h`, `ui/hud.h` |

---

## 📄 Documentation

The full project report covers design decisions, OpenGL rendering techniques, scene breakdowns, and implementation details:

- 📥 [**Download PDF Report**](https://github.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/raw/main/City%20Disaster%20Simulation.pdf)
- 📝 [**Download DOCX Report**](https://github.com/mhtamim136/2D-City-Disaster-Simulation-OpenGL/raw/main/City%20Disaster%20Simulation.docx)

---

## 👨‍💻 Author

<div align="center">

### Murad Hasan Tamim

*CSE Student | Full-Stack & Systems Developer*

[![Portfolio](https://img.shields.io/badge/🌐_Portfolio-mhtamim136.github.io-4f46e5?style=for-the-badge)](https://mhtamim136.github.io)
[![GitHub](https://img.shields.io/badge/GitHub-mhtamim136-181717?style=for-the-badge&logo=github)](https://github.com/mhtamim136)

> 💬 Feel free to reach out via my portfolio for collaboration or inquiries!

</div>

---

<div align="center">

⭐ **If you found this project interesting, please give it a star!** ⭐

</div>
