function printNpop() {
  for (let i = 0; i < 5; i++) {
    if (!stack.length) {
      return false
    } else {
      process.stdout.write(stack.pop().toString() + ' ')
    }
  }
  return true
}

const input = [80, 1 ,2 ,3 ,4, 5 ,-1 ,20 ,30 ,40 ,50, 6 ,7 ,8, 9 ,10, -2, 11 ,12, -3, 33, 22 ,-5]

let queue = []
for (let i = 0; i < input.length; i++) {
  if (!input[i]) break;
  queue.push(input[i])
}

let stack = []
for (let i = 0; i < queue.length; i++) {

  // negative numbers
  if (queue[i] < 0) {
    if (!printNpop()) {
      console.log('\nError: less than 5 numbers left')
      return
    }
  }
  
  // positive numbers
  else if (queue[i] > 0) {
    stack.push(queue[i])
  }
}