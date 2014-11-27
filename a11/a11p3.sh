#! /bin/sh

# this is a test

until test [$(date +%M) * 13 + $(date +%S) * 3] % 17 = 0
do
    echo "I don't like $(date +%M) minutes and $(date +%S) seconds."
    sleep 1
done
echo 123

