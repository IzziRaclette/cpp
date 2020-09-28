
PROGNAME := fil_rouge

WARNFLAGS := -Wall -Wextra
CXXFLAGS := -g -Og --std=c++11
LDFLAGS :=

.SECONDEXPANSION:
.SUFFIXES:


SRCDIR := src
DEPDIR := dep
OBJDIR := obj
BINDIR := bin

$(PROGNAME)_SRC := $(wildcard $(SRCDIR)/*.cpp)


SRCS := $($(PROGNAME)_SRC)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp,$(DEPDIR)/%.d,$(SRCS))


all: $(BINDIR)/$(PROGNAME)
.PHONY: all

clean:
	rm -rf $(BINDIR) $(DEPDIR) $(OBJDIR)
.PHONY: clean


$(BINDIR)/%: $(OBJS)
	@mkdir -p "$(@D)"
	$(CXX) $(WARNFLAGS) $(LDFLAGS) -o "$@" $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p "$(@D)"
	$(CXX) -c $(WARNFLAGS) $(CXXFLAGS) -o "$@" "$<"

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	@mkdir -p "$(@D)"
	$(CXX) $(WARNFLAGS) $(CXXFLAGS) -MM -MF "$@" -MG -MP -MQ "$(OBJDIR)/$*.o" -MQ "$@" "$<"


ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif
