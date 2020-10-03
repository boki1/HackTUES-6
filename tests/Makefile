DEPS=../inc/

ELFs=extended_gcd.elf test_crypto_only.elf test_no_crypto.elf test_with_crypto.elf

CPP=g++ 
CPPFLAGS=-Wextra -g
INCLUDE=-I$(DEPS)

%.o: %.c $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

%.elf: %.o
	$(CPP) $(CPPFLAGS) $< -o $@

tests: $(ELFs)

clean:
	[ -f "*.o" ] && rm *.o
	[ -f "*.elf" ] && rm *.elf

PHONY: clean tests
