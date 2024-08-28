#!/bin/bash

# Test interactive mode
echo "Test interactive mode:"
./hsh <<EOF
/bin/ls
exit
EOF

# Test non-interactive mode with a single command
echo "Test non-interactive mode with a single command:"
echo "/bin/ls" | ./hsh

# Test non-interactive mode with multiple commands
echo "Test non-interactive mode with multiple commands:"
echo "/bin/ls\n/bin/pwd" | ./hsh

# Test env built-in command
echo "Test env built-in command:"
echo "env" | ./hsh

# Test exit built-in command
echo "Test exit built-in command:"
echo "exit" | ./hsh
