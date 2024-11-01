# Embedded Music Player Using ATmega32

This project presents an embedded music player built around the **ATmega32 microcontroller**. The player utilizes a keypad for user input, an LCD for visual feedback, and a speaker for audio output. The system is programmed in C to play musical notes stored in its memory, offering a simple yet functional music player experience on a microcontroller.

## Features

- **Preloaded Songs**: Includes a selection of preloaded songs such as "Every Breath You Take" and "I Was Never There" with multiple pitch variations.
- **User Interaction**: Allows users to select and control music playback using a keypad.
- **Visual Feedback**: Displays current status and song information on a 16x2 LCD screen.
- **Audio Output**: Outputs sound through a connected speaker, producing different pitches for each musical note.

## Components

- **ATmega32 Microcontroller**: Core processing unit managing inputs, outputs, and music playback.
- **Keypad**: Provides user interface for selecting and controlling music playback.
- **16x2 LCD Module**: Displays information such as current track and status.
- **Speaker**: Outputs the musical notes.
- **Power Supply**: Provides necessary operating voltage for the circuit.

## Circuit Design

- **Keypad Interface**: Connected to the ATmega32 to capture user inputs.
- **LCD Display**: Connected to the microcontroller to show current status and track information.
- **Speaker Connection**: Driven by the microcontroller to play musical notes.
- **Power Supply**: Ensures stable operation of all components.

## Available Songs

The following songs are preloaded into the music player and can be selected using the keypad:

1. **Every Breath You Take** – High and low pitch variations
2. **I Was Never There** – High, medium, and low pitch variations

Each song is composed of musical notes stored in memory, allowing for quick playback upon selection.

## How It Works

1. **User Input**: The user selects a song or controls playback using the keypad.
2. **Processing**: The ATmega32 processes the input, retrieves the corresponding musical notes from memory, and controls playback.
3. **Output**:
   - **Audio**: The microcontroller generates signals to produce sound through the speaker.
   - **Visual**: The LCD displays the current song and playback status.

## Getting Started

### Prerequisites

- **ATmega32 Development Board** or equivalent setup.
- **AVR Programming Tools**: To compile and upload the code to the microcontroller.
- **Keypad**: For user input.
- **16x2 LCD Module**: For displaying information.
- **Speaker**: For audio output.
- **Breadboard and Connecting Wires**: For assembling the circuit.

### Setup Instructions

1. **Circuit Assembly**:
   - Connect the keypad to the ATmega32's input ports.
   - Interface the LCD module with the microcontroller.
   - Connect the speaker to the appropriate output pin of the ATmega32.
   - Ensure all components are properly powered.
2. **Programming**:
   - Compile the provided C code using an AVR compiler.
   - Upload the compiled code to the ATmega32 using a suitable programmer.
3. **Operation**:
   - Power up the system.
   - Use the keypad to select and control music playback.
   - Observe the status on the LCD and listen to the audio output from the speaker.

## Code Overview

The C program initializes the keypad, LCD, and speaker interfaces. It includes functions to read user inputs, manage music playback, and update the display accordingly. Musical notes are stored in the microcontroller's memory and are played based on user selection.

## Notes

- **Customization**: The musical notes and songs can be modified in the code to play different melodies.
- **Volume Control**: Implementing a volume control feature can enhance user experience.
- **Power Supply**: Ensure a stable power supply to prevent malfunctions.
