# devkitPro Wii U homebrew Makefile
.SUFFIXES:
ifeq ($(strip $(DEVKITPRO)),)
$(error "DEVKITPRO is not set. Install the devkitPro Wii U toolchain.")
endif

TARGET := MultiEmulatorU
BUILD := build
SOURCES := source
DATA :=
INCLUDES :=
CFLAGS := -Wall -Wextra -O2 -ffunction-sections -fdata-sections
CXXFLAGS := $(CFLAGS) -std=gnu++17
LDFLAGS := -Wl,--gc-sections
LIBS := -lwut

include $(DEVKITPRO)/wut/share/wut_rules
