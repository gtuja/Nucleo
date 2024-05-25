
# List of abbreviation
- GSL G? Static Library
- NPA Nucleo Playground Application
- STM ST Microcontroller
- IDE Integrated Development Environment
- GSL.SML GSL State Machine Library
- HLD High Level Design

# 1. preface
- GSL is a collection of static libraries for general purpose written in C language.
- NPA is a collection of applications run on STM.
- NPA shall evaluate GSL and might play a role as a template application using GSL.

# 2. Environment
- NPA shall run on the STM, e.g., nucleo-f429ZI, nucleo-l053r8.
- NPA shall be implemented with CubeIDE version 1.51 provided by STM.

# 3. Restrictions
- Feature specific restrictions, e.g., clocks, ROM, RAM, shall be defined during evaluation phase.

# 4. Project Structures
- Root
   GSL
   nucleo-l053r8
   nucleo-f429ZI

# 5. Features
## 5.1. GSL
- GSL is comprised of of modular libraries, e.g, SML, etc.
- GSL shall provide closed processes, e.g., state control, to application.
### 5.1. GSL.SML
#### 5.1.1. Overall
- SML shall provide state control to applications with same states.
#### 5.1.2. HLD

#### 5.1.3. Events
- SML shall define abstract events for applications.
- SML shall notify events to applications, during state control.
- Event extraction shall be done by applications with callback function.

### 5.2. 

