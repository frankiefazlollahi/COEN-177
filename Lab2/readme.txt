When running the provided program I immediately got a segmentation fault (core dumped) message.

Running the command with ./step3 3000 delay, there was 1 time where either parent or child was run two times in a row (duplicate lines, non-alternating) before the other.

Running the command with ./step3 500 delay, there was only 3 times with duplicate lines, but child finished earlier than the parent, resulting in parent running 2 times in a row at the end (98, 99).

Running the command with ./step3 5000 delay, parent started first, and finished last. There was only 1 duplicated line (child).
