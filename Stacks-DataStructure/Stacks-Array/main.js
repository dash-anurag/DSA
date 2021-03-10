class Stack {
  constructor() {
    this.array = [];
  }

  peek() {
    console.log(this.array[this.array.length - 1]);
    return this.array[this.array.length - 1];
  }

  push(value) {
    this.array.push(value);
    console.log(this);
    return this;
  }

  pop() {
    this.array.pop();
    console.log(this);
    return this;
  }
}

const myStack = new Stack();

myStack.push("Google");
myStack.push("Udemy");
myStack.push("Reddit");

myStack.peek();

myStack.pop();
myStack.pop();
myStack.pop();
