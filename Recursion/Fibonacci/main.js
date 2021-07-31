// recursive
const fibonacci = (idx) => {
  if (idx <= 1) {
    return idx;
  }

  return fibonacci(idx - 1) + fibonacci(idx - 2);
};

const advancedFibonacci = (idx) => {
  let arr = [0, 1];
  for (let i = 2; i <= idx; i++) {
    arr.push(arr[i - 1] + arr[i - 2]);
  }

  return arr[idx];
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
