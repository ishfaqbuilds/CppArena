import random
import os
from colorama import Fore, Style, init

init(autoreset=True)


def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')


def show_banner():
    print("\n")
    print(Fore.YELLOW + Style.BRIGHT + "🎰 =============================== 🎰")
    print(Fore.YELLOW + Style.BRIGHT + "         SLOT MACHINE GAME         ")
    print(Fore.YELLOW + Style.BRIGHT + "🎰 =============================== 🎰\n")


MAX_LINES = 3
MAX_BET = 100
MIN_BET = 1

ROWS = 3
COLUMNS = 3

symbolCount = {
    "A": 6,
    "B": 6,
    "C": 6,
    "D": 6
}

symbolValue = {
    "A": 5,
    "B": 4,
    "C": 3,
    "D": 2
}


def check_winnings(slotColumns, lines, bet, values):
    """
    We Check Which Lines Win Based On Slot Results!
    """
    winnings = 0
    winningLines = []

    for line in range(lines):
        symbol = slotColumns[0][line]
        won = True

        for column in slotColumns:
            to_check = column[line]
            if to_check != symbol:
                won = False
                break

        if won:
            winnings += values[symbol] * bet
            winningLines.append(line + 1)

    return winnings, winningLines


def get_slot_machine_spin(numRows, numCols, symbolDict):
    """
    We Generate A Random Slot Machine Spin!
    """
    allSymbols = []
    for symbol, count in symbolDict.items():
        for _ in range(count):
            allSymbols.append(symbol)

    slotColumns = []
    for _ in range(numCols):
        column = []
        currentSymbols = allSymbols[:]
        for _ in range(numRows):
            value = random.choice(currentSymbols)
            currentSymbols.remove(value)
            column.append(value)

        slotColumns.append(column)

    return slotColumns


def print_slot_machine(slotColumns):
    """
    We Display The Slot Machine Grid With Colors!
    """
    numRows = len(slotColumns[0])
    numCols = len(slotColumns)

    print(Fore.CYAN + "+---" * numCols + "+" + Style.RESET_ALL)

    for row in range(numRows):
        for i, column in enumerate(slotColumns):
            symbol = column[row]

            if symbol == "A":
                symbol = Fore.GREEN + symbol + Style.RESET_ALL
            elif symbol == "B":
                symbol = Fore.BLUE + symbol + Style.RESET_ALL
            elif symbol == "C":
                symbol = Fore.MAGENTA + symbol + Style.RESET_ALL
            elif symbol == "D":
                symbol = Fore.RED + symbol + Style.RESET_ALL

            if i != numCols - 1:
                print(Fore.CYAN + f"| {symbol} " + Style.RESET_ALL, end="")
            else:
                print(Fore.CYAN + f"| {symbol} |" + Style.RESET_ALL)

    print(Fore.CYAN + "+---" * numCols + "+" + Style.RESET_ALL)


def deposit():
    """
    We Ask The User To Input An Initial Deposit!
    """
    clear_screen()
    show_banner()

    while True:
        amount = input("Enter Deposit Amount ($): ")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                clear_screen()
                return amount
            print("Amount must be greater than zero!")
        else:
            print("Please enter a valid number!")


def get_number_of_lines():
    """
    We Ask The User How Many Lines They Want To Bet On!
    """
    while True:
        lines = input(f"Enter the number of lines to bet on (1 - {MAX_LINES}): ")
        if lines.isdigit():
            lines = int(lines)
            if 1 <= lines <= MAX_LINES:
                clear_screen()
                return lines
            print(f"Enter a number between 1 and {MAX_LINES}!")
        else:
            print("Please enter a valid number!")


def get_bet():
    """
    We Ask The User For Bet Amount Per Line.
    """
    while True:
        clear_screen()
        show_banner()
        amount = input(f"Enter your bet per line (${MIN_BET} - ${MAX_BET}): ")
        if amount.isdigit():
            amount = int(amount)
            if MIN_BET <= amount <= MAX_BET:
                clear_screen()
                return amount
            print(f"Bet must be between ${MIN_BET} and ${MAX_BET}!")
        else:
            print("Please enter a valid number!")


def spin(balance):
    """
    We Execute One Spin Of The Slot Machine.
    """
    clear_screen()
    show_banner()

    lines = get_number_of_lines()

    while True:
        bet = get_bet()
        totalBet = bet * lines

        if totalBet > balance:
            print(f"\nNot enough balance. Current balance: ${balance}\n")
        else:
            break

    clear_screen()
    show_banner()
    print("----- Bet Summary -----")
    print(f"Deposited Balance : ${balance}")
    print(f"Lines Selected    : {lines}")
    print(f"Bet Per Line      : ${bet}")
    print(f"Total Bet         : ${totalBet}")
    print("-----------------------\n")

    slots = get_slot_machine_spin(ROWS, COLUMNS, symbolCount)
    print_slot_machine(slots)

    winnings, winningLines = check_winnings(slots, lines, bet, symbolValue)
    balance = balance - totalBet + winnings

    if winnings > 0:
        print(Fore.GREEN + f"\n💰 You Won ${winnings}!")
        print(Fore.GREEN + "Winning Lines: " + ", ".join(map(str, winningLines)))
    else:
        print(Fore.RED + "\nNo Winning Lines This Time!")

    return balance


def main():
    balance = deposit()

    while True:
        print(f"\nCurrent Balance: ${balance}")
        choice = input("\nPress ENTER to play or type 'ESC' to quit: ").strip().lower()
        clear_screen()

        if choice == "esc":
            clear_screen()
            print(Fore.YELLOW + Style.BRIGHT + "🎰 =============================== 🎰")
            print(Fore.YELLOW + Style.BRIGHT + "        THANKS FOR PLAYING!        ")
            print(Fore.YELLOW + Style.BRIGHT + "🎰 =============================== 🎰\n")
            break

        balance = spin(balance)

        if balance <= 0:
            clear_screen()
            print(Fore.RED + Style.BRIGHT + "🎰 =============================== 🎰")
            print(Fore.RED + Style.BRIGHT + "            GAME OVER              ")
            print(Fore.RED + Style.BRIGHT + "🎰 =============================== 🎰\n")
            print(Fore.RED + "You have no money left!")
            break


main()
