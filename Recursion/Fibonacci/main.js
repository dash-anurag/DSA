// recursive
const fibonacci = (idx) => {
  if (idx <= 1) {
    return idx;
  }

  return fibonacci(idx - 1) + fibonacci(idx - 2);
};

const advancedFibonacci = (idx) => {
  let temp = new Array(idx + 2);
  temp[0] = 0;
  temp[1] = 1;

  for (let i = 2; i <= idx; i++) {
    temp[i] = temp[i - 1] + temp[i - 2];
  }

  return temp[idx];
};

num = 100;

// console.log(
//   `The value in the Fibonacci Sequence with index ${num} is : ${fibonacci(num)}`
// );

console.log(
  `The value in the Fibonacci Sequence with index ${num} is : ${advancedFibonacci(
    num
  )}`
);
