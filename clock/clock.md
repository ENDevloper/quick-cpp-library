# Clock
##### Author
by ENDevolper
## What clock does.
Clock is a data-type you can define boundries for. If they go below or over these boundries the value will automatically loop back.
## Operations:
### Normal Operations
#### clock | gets clock value
clock | returns value within the boundries of clock
#### + | performs addition
clock \+ number or clock2 | returns a double that is whithin the boundries of clock
number \+ clock | returns a double that might be outside the boundries of clock
#### - | performs subtraction
clock \- number or clock2 | returns a double that is whithin the boundries of clock
number \- clock | returns a double that might be outside the boundries of clock
#### * | performs multiplication
clock \* number or clock2 | returns a double that is whithin the boundries of clock
number \* clock | returns a double that might be outside the boundries of clock
#### / | performs division
clock / number or clock2 | returns a double that is whithin the boundries of clock
number / clock | returns a double that might be outside the boundries of clock
#### % | performs modulo calculation
clock % number or clock2 | returns a double that is whithin the boundries of clock
number % clock | returns a double that might be outside the boundries of clock
### Q Operations
#### ++ | adds 1 to clock
clock++ | value of clock might not be within the boundries of clock
#### -- | subtracts 1 from clock
clock-- | value of clock might not be within the boundries of clock
### Zap Operations
#### += | adds to clock
clock += number or clock2 | value of clock might not be within the boundries of clock
#### -= | adds to clock
clock -= number or clock2 | value of clock might not be within the boundries of clock
#### *= | adds to clock
clock *= number or clock2 | value of clock might not be within the boundries of clock
#### /= | adds to clock
clock /= number or clock2 | value of clock might not be within the boundries of clock
#### %= | adds to clock
clock %= number or clock2 | value of clock might not be within the boundries of clock
#### clock.zget(); | gets clock value
clock.zget(); | value of clock might not be within the boundries of clock.
