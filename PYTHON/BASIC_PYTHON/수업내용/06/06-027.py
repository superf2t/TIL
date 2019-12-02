#06-027.py

import re

phone1 = re.compile(r'\(\d{3}\)\s?\d{3}-\d{4}')
phone2 = re.compile(r'''(
    \(\d{3}\)    # area code
    \s?              # white space  (0 or 1)
    \d{3}           # first 3 digits
    -                  # seperator
    \d{4}           # last 4 digits
)''', re.VERBOSE)
ret = re.search(phone1, 'Phone: (031) 234-2345')
print(ret.group())

