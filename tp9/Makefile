
PROGNAME := tp9

CXXFLAGS := --std=c++14
LDFLAGS  :=

MKDIR := mkdir

SRCDIR := src
OBJDIR := obj
BINDIR := bin
DEPDIR := dep

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp,$(DEPDIR)/%.mk,$(SRCS))

all: $(BINDIR)/$(PROGNAME)
.PHONY: all

clean:
	rm -rf $(BINDIR) $(OBJDIR) $(DEPDIR)
.PHONY: clean

# Make sure this is simply-expanded! It needs to be expanded within the rule.
MKPARENT = @$(MKDIR) -p "$(@D)"

$(BINDIR)/$(PROGNAME): $(OBJS)
	$(MKPARENT)
	$(CXX) $(LDFLAGS) -o "$@" $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(MKPARENT)
	$(CXX) $(CXXFLAGS) -c -o "$@" "$<"

$(DEPDIR)/%.mk: $(SRCDIR)/%.cpp
	$(MKPARENT)
	$(CXX) $(CXXFLAGS) -MM -MF "$@" -MQ "$@" -MQ "$(OBJDIR)/$*.o" -MP -MG $<

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
