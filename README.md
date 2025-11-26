# AES-128 Hardware Accelerator & SoC Integration

This project implements an AES-128 encryption hardware accelerator on an Altera Cyclone II FPGA, integrated into a System-on-Chip (SoC) using the Avalon-MM interface. It includes both the Verilog hardware design and the Nios II software driver.

## Project Overview

The system offloads AES-128 encryption tasks from the CPU to a dedicated hardware accelerator. The hardware core handles key expansion and encryption rounds, while the software running on a Nios II processor manages data input/output and control signals.

## Hardware Architecture

The hardware design is modular, consisting of the following key components:

- **AES_Top**: The top-level wrapper that integrates the System Controller, Input Interface, Key Logic, and Processing Core.
- **AES_EncryptionCore**: Contains the main encryption datapath.
- **KeyLogic**: Handles the AES key expansion algorithm.
- **ProcessingCore**: Executes the AES encryption rounds (SubBytes, ShiftRows, MixColumns, AddRoundKey).
- **SystemController**: A Finite State Machine (FSM) that orchestrates the overall operation, managing handshakes between the processor and the accelerator.
- **InputInterface**: Manages data loading from the system bus.

## Software Interface

The software application is located in the `software/helloAES` directory.

- **helloAES**: A C-based Nios II application that interacts with the hardware accelerator.
- **Interaction**: The software writes the encryption key and plaintext data to specific memory-mapped addresses of the accelerator (Avalon-MM Slave) and polls for completion status before reading back the ciphertext.

## Directory Structure

- `AES_128.qpf`: Quartus II project file.
- `software/`: Contains the Nios II C/C++ application code.
- `*.v`: Verilog HDL source files for the hardware modules.
- `system.qsys`: Qsys system integration file.

## Credits

Based on: https://github.com/QuangTheGreat/AES-128-IP-Hardware-and-SoC-Integration-on-Altera-Cyclone-II-FPGA

## Result
[Youtube ](https://youtu.be/IiOmxwstXxs?si=AY4OhlfCqvZndW_H)


<img width="766" height="663" alt="image" src="https://github.com/user-attachments/assets/7decbe9b-afee-460c-ba3c-d2d67f396c86" />
