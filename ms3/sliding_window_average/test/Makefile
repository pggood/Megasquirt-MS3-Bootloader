# Make tests using CppUTest framework
PRODUCTION_CODE_DIR=..

TEST_OBJS=\
		  AllTests.o \
		  test.o
			
PRODUCTION_OBJS=\
				sliding_window_average.o

OBJS=$(TEST_OBJS) $(PRODUCTION_OBJS)

CPPUTEST_BASE_LIBNAMES=\
					   CppUTest \
					   CppUTestExt

#create the list of libs to be added to the link command 
LIBS += $(addprefix -l,$(CPPUTEST_BASE_LIBNAMES))

EXE=test
EXES=$(EXE)

CFLAGS+=-ffunction-sections \
		-fdata-sections \
		-I..
		  
LDFLAGS+=-Wl,--gc-sections

all: $(EXES)

check: all
	@for exe in $(EXES) ; do \
		./$$exe || exit 1 ; \
	done

$(EXE): $(OBJS)
	@$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS) 

%.o: %.cpp
	@$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o: $(PRODUCTION_CODE_DIR)/%.c
	@$(CC) -c $(CFFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS) $(EXES)

.PHONY: all clean check


