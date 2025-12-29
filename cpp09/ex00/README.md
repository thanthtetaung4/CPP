Bitcoin Exchange (btc) - README

Overview

This small C++98 program calculates the bitcoin value on given dates using a provided historical database (CSV). It reads a database file `data.csv` containing daily bitcoin exchange rates, and a user-supplied input file containing lines of the form "date | value". For each input line the program prints the resulting fiat value (rate * value) or an error message if the input is malformed or invalid.

Repository layout

- main.cpp          - program entrypoint; constructs BitcoinExchange and processes input file
- BitcoinExchange.hpp
- BitcoinExchange.cpp
- data.csv          - provided bitcoin exchange database (CSV: date,exchange_rate) — included with the subject
- input.txt         - example input file (date | value)
- Makefile          - builds the `btc` executable

Build

The project targets C++98. To build, run the Makefile in the project folder:

```sh
make
```

This creates the `btc` binary.

Usage

- Run without an argument:
  - ./btc
  - prints: "Error: could not open file."

- Run with an input file:
  - ./btc input.txt
  - The input file must be plain text. Each non-header line must be in the form:
    date | value
    where date is YYYY-MM-DD and value is a positive number (float or integer) between 0 and 1000.

Input file format details

- The program expects the first line of `input.txt` to be a header (e.g. "date | value"); that header line is skipped.
- Each subsequent line should either be in the form "YYYY-MM-DD | <number>" or the program will print an error for that line.
- Whitespaces around date and value are tolerated (trimmed).

Database format (`data.csv`)

- `data.csv` is expected to have a header in the first line: "date,exchange_rate" and subsequent lines with CSV entries like:
  2011-01-03,0.3
- The database is read once when the `BitcoinExchange` object is constructed and stored in a `std::map<std::string, float>` keyed by the date string.

Lookup rules

- If an input date exactly matches a date in the DB, the rate from that date is used.
- If the input date does not exist in the DB, the program uses the closest earlier date (lower bound behavior). If there is no earlier date available, the program prints an error for that input line.

Validation and error messages

- Date validation:
  - Format: YYYY-MM-DD (checked with POSIX regex + range checks including leap years)
  - If invalid, the program prints: "Error: bad input => <date>"

- Value validation:
  - Parsed with a stringstream to detect malformed numbers.
  - Must be between 0 and 1000 inclusive.
  - If negative: prints "Error: not a positive number."
  - If > 1000: prints "Error: too large a number."

- Malformed input lines (missing '|', non-numeric value, etc.) produce: "Error: bad input => <the whole line trimmed>"

Example run

Using the provided `input.txt` example, the output will be:

2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.

Implementation notes

- The database is stored in a `std::map<std::string, float>` (meets the "use at least one container" requirement).
- The code avoids C++11 features and compiles with `-std=c++98`.
- Date string comparisons work because dates are formatted YYYY-MM-DD, allowing lexicographic ordering.

Testing

- Build and run the sample as shown above. To compare output automatically, capture stdout and diff against an expected-output file.

Possible improvements

- Reject scientific notation or exponential numeric formats if you want stricter numeric rules.
- Add unit tests for date parsing and lookup behavior.
- Improve error codes or return values for use in scripts.

If you want, I can add a short test script that runs the sample input and asserts exact output match. Let me know which improvement you prefer.
