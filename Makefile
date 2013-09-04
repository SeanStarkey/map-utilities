
# Generic makefile to build/install a static library (zlib example)
ARCH      = linux
CFLAGS    = -O3 -Wall

# List of source code directories
SOURCES   = src

TESTSOURCES = test

#List of header files to install
INCLUDES  = src/Location.h \
						src/LocationDeg.h \
						src/LocationDegMinSec.h \
						src/Distance.h \
						src/Constants.h

# Library to create
LIBNAME   = libmaputil.a
SHORTLIBNAME = maputil

VPATH = $(SOURCES)

libdir = lib/$(ARCH)
includedir = include
INSTALL_PROGRAM = install -D
INSTALL_DATA = $(INSTALL_PROGRAM) -m 644

LIBNAME   = libmaputil.a

############################################################

BUILD_DIR   = build/$(ARCH)

TARGET      = $(BUILD_DIR)/$(LIBNAME)

TESTTARGET  = $(BUILD_DIR)/test/testapp

CSOURCES   := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c))
CPPSOURCES := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.cpp))
COBJECTS   := $(addprefix $(BUILD_DIR)/,$(patsubst %.c,%.o,$(notdir $(CSOURCES))))
CPPOBJECTS := $(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o,$(notdir $(CPPSOURCES))))
OBJECTS    := $(COBJECTS) $(CPPOBJECTS)
TESTCFILES := $(foreach dir,$(TESTSOURCES),$(wildcard $(dir)/*.c))
TESTCPPFILES := $(foreach dir,$(TESTSOURCES),$(wildcard $(dir)/*.cpp))
TESTCOBJECTS := $(addprefix $(BUILD_DIR)/,$(TESTCFILES:.c=.o))
TESTCPPOBJECTS := $(addprefix $(BUILD_DIR)/,$(TESTCPPFILES:.cpp=.o))
TESTOBJECTS := $(TESTCOBJECTS) $(TESTCPPOBJECTS)

LIBS := -lm


.PHONY: all installdirs install uninstall clean

# Default
default: $(TARGET)

test: default install $(TESTTARGET)
	$(TESTTARGET)

$(TARGET): $(BUILD_DIR) $(OBJECTS)
	$(AR) -rc $(TARGET) $(OBJECTS)

$(TESTTARGET): $(TESTOBJECTS)
	$(CXX) -o $(TESTTARGET) $? -l$(SHORTLIBNAME) -lcppunit -lcunit -lm -L$(libdir)

# Compile C source to object code
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(includedir) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -I$(includedir) -c $< -o $@

# Create the necessary directory tree for the build
$(BUILD_DIR):
	@for p in $(SOURCES); do mkdir -p $(BUILD_DIR)/$$p; done
	@for p in $(TESTSOURCES); do mkdir -p $(BUILD_DIR)/$$p; done

# Create the necessary directory tree for installation
installdirs:
	@mkdir -p $(libdir)
	@mkdir -p $(includedir)

# Install the library and headers
install: default installdirs
	$(INSTALL_DATA) $(TARGET) $(libdir)
	for p in $(INCLUDES); do $(INSTALL_DATA) $$p $(includedir); done

# Remove the library and headers
uninstall:
	rm -f $(libdir)/$(LIBNAME)
	for p in $(notdir $(INCLUDES)); do rm -f $(includedir)/$$p; done

# Remove all build files
clean:
	rm -fr build lib $(includedir) *~ src/*~ test/*~
