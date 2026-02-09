CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = main.o bankAccountType.o accountsDatabase.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o funcationalUI.o

run-tests: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp accountsDatabase.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o funcationalUI.o

highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h bankAccountType.o  savingsAccountType.o

savingsAccountType.o: savingsAccountType.cpp savingsAccountType.h bankAccountType.o

certificateOfDepositType.o: certificateOfDepositType.cpp certificateOfDepositType.h bankAccountType.o

bankAccountType.o: bankAccountType.cpp bankAccountType.h

accountsDatabase.o: accountsDatabase.cpp accountsDatabase.h

funcationalUI.o: funcationalUI.cpp functionalUI.h accountsDatabase.o

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h checkingAccountType.o

highInterestCheckingType.o: highInterestCheckingType.cpp highInterestCheckingType.h noServiceChargeCheckingType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h checkingAccountType.o

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h bankAccountType.o

clean:
	rm -f run-tests *.o *~

.PHONY: run run-tests clean
run: run-tests
	./run-tests
