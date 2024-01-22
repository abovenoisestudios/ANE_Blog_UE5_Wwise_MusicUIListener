# How to Create an Audio Manager in Unreal Engine
### Game Audio Blog - Above Noise Studios
English: [https://abovenoisestudios.com/blogeng/wwiseue5listener2dmusicuieng](https://abovenoisestudios.com/blogeng/wwiseue5listener2dmusicuieng)\
Spanish: [https://abovenoisestudios.com/blogespanol/wwiseue5listener2dmusicuiesp](https://abovenoisestudios.com/blogespanol/wwiseue5listener2dmusicuiesp)\
\
Created By: Horacio Valdivieso\
[horacio@abovenoisestudios.com](mailto:horacio@abovenoisestudios.com)\
[LinkedIn](https://www.linkedin.com/in/horaciovaldivieso/)

---
_Unreal Engine Version: **5.3.2**_\
_Wwise Version: **2023.1.0.8367**_

### **English:**
This repository contains an Unreal Engine 5 project, and a Wwise project.
It uses a third-person template created with the Epic Games Launcher.
This project shows how to register a 2D (Non-Spatial Audio) listener and a Wwise Object to post Music and UI sounds that don’t require 3D positioning in the Game World.

**How to Use?:**\
To download this project, click on the **Code** button and **Download Zip**.

To rebuild and compile the project, ensure you have [Visual Studio](https://visualstudio.microsoft.com/) for Windows or [Xcode](https://download.developer.apple.com/Developer_Tools/Xcode_13.4.1/Xcode_13.4.1.xip) for Mac.
Right-click on **MyUEProject.uproject** and choose **"Generate Visual Studio Project Files"** on Windows or **Services > "Generate Xcode project"** on Mac.
Double-click on **MyUEProject.uproject** to open the UE5 project.

**Rebuild the project:**

<img height="261" src="Images/Rebuild Project.png" width="249"/>

**About Compiler Versions:**

WINDOWS:

- _Visual Studio 2019 v16.11.5 to 2022 are currently compatible with UE5_.
- _Its essential to install these Workloads: **".NET Desktop Development"**, **"Desktop Development With C++"**, and **"Game Development With C++"**._\
  **Here is a useful video on how to set up VS for UE5 Development:** [LINK](https://youtu.be/8xJRr6Yr_LU?t=105)

MAC:
- _Xcode v14.1 to 15.2 are currently compatible with UE5_.

Enjoy!

### **Spanish:**
Este repositorio contiene un proyecto en Unreal Engine 5, y un proyecto Wwise.
Usa una maqueta en primera persona creada con el Epic Games Launcher.
Este proyecto muestra cómo registrar un listener 2D (Audio No Spacializado) y un Objecto Wwise para reproducir música y sonidos UI que no requieren de posicionamiento 3D en el mundo del juego.

**Cómo Usar?:**\
Para descargar este proyecto, da click en el botón **Code** y luego en **Download Zip**.

Para construir y compilar el proyecto, asegúrate de tener [Visual Studio](https://visualstudio.microsoft.com/) para Windows o [Xcode](https://download.developer.apple.com/Developer_Tools/Xcode_13.4.1/Xcode_13.4.1.xip).
Haz click derecho en **MyUEProject.uproject** y selecciona **"Generate Visual Studio Project Files"** en Windows o **Services > "Generate Xcode project"** en Mac.
Haz doble click en **MyUEProject.uproject** para abrir el proyecto UE5.

**Reconstruye el proyecto:**

<img height="261" src="Images/Rebuild Project.png" width="249"/>

**Sobre las versiones del compilador:**

WINDOWS:

- _Visual Studio 2019 v16.11.5 a la 2022 son actualmente compatibles con UE5_.
- _Es esencial instalar estas cargas de trabajo: **".NET Para El Escritorio"**, **"Desarrollo Para El Escritorio Con C++"**, y **"Desarrolo De Juegos Con C++"**._\
  **Aquí hay un vídeo muy útil sobre cómo configurar VS para desarrollo en UE5:** [LINK](https://youtu.be/8xJRr6Yr_LU?t=105)

MAC:

- _Xcode v14.1 a la 15.2 son actualmente compatibles con UE5_.

Disfruta!

## C++ Implementation

![](Images/9_RegisterAkGameObjectsImp.png)

## Blueprint Implementation

![](Images/17_StopCurrentMusicEventBP.png)
