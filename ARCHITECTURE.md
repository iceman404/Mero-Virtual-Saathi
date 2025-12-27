# Architecture Documentation

## Overview

Mero Virtual Saathi is built with a modular, cross-platform architecture that separates concerns and provides clean interfaces between components.

## System Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    Main Application                     │
│                      (main.cpp)                         │
└────────────────────┬────────────────────────────────────┘
                     │
        ┌────────────┴────────────┐
        │                         │
┌───────▼────────┐      ┌────────▼────────┐
│  Console UI    │      │  Speech Analyzer│
│  (BoundaryFrame)│      │  (Word Analysis)│
└───────┬────────┘      └────────┬────────┘
        │                        │
        │              ┌─────────▼─────────┐
        │              │ Response Generator │
        │              └─────────┬─────────┘
        │                        │
┌───────▼────────────────────────▼────────┐
│         Platform Abstraction            │
│  (Console, System Calls, TTS)           │
└───────┬────────────────────────────────┘
        │
┌───────▼────────┐      ┌──────────────┐
│   Database     │      │ Conversation │
│   Manager      │      │   Manager    │
└────────────────┘      └──────────────┘
```

## Component Details

### 1. Platform Abstraction Layer (`platform.h/cpp`)

**Purpose:** Provides cross-platform interfaces for OS-specific operations.

**Responsibilities:**
- Console cursor positioning
- Screen clearing
- Character input (non-echo)
- Sleep/delay operations
- URL/file opening
- System command execution

**Platform Support:**
- Windows: Uses Windows API (`windows.h`, `conio.h`)
- Linux: Uses ANSI escape codes and termios
- macOS: Uses termios and system commands

### 2. Text-to-Speech Abstraction (`tts.h/cpp`)

**Purpose:** Unified interface for text-to-speech across platforms.

**Implementation:**
- **Windows:** eSpeak
- **Linux:** pico2wave (primary), eSpeak (fallback)
- **macOS:** say command

**Features:**
- Configurable amplitude, pitch, and speed
- Voice selection
- Automatic fallback mechanisms

### 3. Console UI (`console_ui.h/cpp`)

**Purpose:** Renders the user interface and handles visual presentation.

**Components:**
- `BoundaryFrame`: Draws frames and borders
- Intro screen with ASCII art
- Communication frames for Saathi and User
- Cursor management

### 4. Speech Analyzer (`speech_analyzer.h/cpp`)

**Purpose:** Analyzes user input and classifies sentence types.

**Classification:**
- **Questions:** Detects question words (what, where, who, etc.)
- **Tasks:** Detects action words (do, make, open, etc.)
- **Greetings:** Detects greeting words (hello, namaste, etc.)
- **Statements:** Default classification for other inputs

**Algorithm:**
- Pattern matching using keyword arrays
- Case-insensitive matching
- Word boundary detection

### 5. Response Generator (`response_generator.h/cpp`)

**Purpose:** Generates appropriate responses based on input classification.

**Handlers:**
- `handleQuestion()`: Answers questions about countries, Saathi identity
- `handleTask()`: Executes system tasks (open apps, URLs)
- `handleGreeting()`: Responds to greetings
- `handleStatement()`: Responds to statements

**Features:**
- Database queries for country information
- System integration (app launching, URL opening)
- Secret code authentication for database modifications
- Random response selection for variety

### 6. Database Manager (`database.h/cpp`)

**Purpose:** Manages persistent storage of country information.

**Operations:**
- `initialize()`: Creates database if it doesn't exist
- `addCountry()`: Adds new country entry
- `findCountry()`: Searches for country by name
- `modifyCountry()`: Updates existing country information
- `countryExists()`: Checks if country exists

**Storage:**
- Binary file format (`country_database.bin`)
- Fixed-size structures for efficiency
- Case-insensitive search

### 7. Conversation Manager (`conversation.h/cpp`)

**Purpose:** Manages conversation state and greeting system.

**Features:**
- Random greeting selection
- Conversation history tracking
- State persistence
- Dynamic greeting database

**Storage:**
- Binary file format (`Greetings_Initialization.bin`)
- Stores user inputs as conversation history

## Data Flow

### User Input Processing

```
User Input
    │
    ▼
Speech Analyzer (classify input)
    │
    ▼
Response Generator (process based on type)
    │
    ├──► Question Handler
    ├──► Task Handler
    ├──► Greeting Handler
    └──► Statement Handler
    │
    ▼
Database/System Operations
    │
    ▼
Response Display + TTS
    │
    ▼
Conversation Manager (update state)
```

### Database Query Flow

```
User: "What is the capital of Nepal?"
    │
    ▼
Speech Analyzer: Question detected
    │
    ▼
Response Generator: Extract country name and query type
    │
    ▼
Database Manager: Search country_database.bin
    │
    ▼
Response: "Hey, It's capital is: Kathmandu"
    │
    ▼
TTS: Speak response
```

## Design Patterns

### 1. Abstraction Pattern
- Platform-specific code is abstracted through interfaces
- Allows easy addition of new platforms

### 2. Strategy Pattern
- Different response handlers for different input types
- Extensible response generation

### 3. Singleton-like Pattern
- Static methods for managers (Database, Conversation)
- Centralized state management

### 4. Factory Pattern (implicit)
- Response generation based on input classification

## Extension Points

### Adding New Response Types

1. Add keyword detection in `SpeechAnalyzer`
2. Add handler method in `ResponseGenerator`
3. Update `processInput()` to route to new handler

### Adding New Platforms

1. Add platform detection in `platform.h`
2. Implement platform-specific functions in `platform.cpp`
3. Update `tts.cpp` for platform-specific TTS

### Adding New Database Fields

1. Update `Country` structure in `types.h`
2. Update database read/write operations
3. Update response handlers to use new fields

## Performance Considerations

- **Binary File I/O:** Fast sequential access
- **Pattern Matching:** Linear search through keyword arrays (acceptable for small sets)
- **TTS:** Asynchronous execution to avoid blocking
- **Memory:** Fixed-size structures prevent dynamic allocation overhead

## Security Considerations

- Secret code authentication for database modifications
- Input validation (though basic)
- File path handling to prevent directory traversal
- No network operations (local-only)

## Future Improvements

1. **NLP Enhancement:** Use proper NLP libraries for better understanding
2. **Database:** Migrate to SQLite for better query capabilities
3. **Configuration:** JSON/YAML configuration files
4. **Logging:** Proper logging system
5. **Testing:** Unit tests for each module
6. **Plugin System:** Allow custom response handlers

