class Node {
  constructor(value) {
    (this.value = value), (this.next = null), (this.prev = null);
  }
}

class DoublyLinkedList {
  constructor(value) {
    this.head = {
      value: value,
      next: null,
      prev: null,
    };
    this.tail = this.head;
    this.length = 1;
  }

  append(value) {
    const newNode = new Node(value);

    newNode.prev = this.tail;
    this.tail.next = newNode;
    this.tail = newNode;
    this.length++;
    // console.log(this);
    return this.printList();
  }

  prepend(value) {
    const newNode = new Node(value);

    newNode.next = this.head;
    this.head.prev = newNode;
    this.head = newNode;
    this.length++;
    console.log(this);
    return this.printList();
  }

  insert(value, index) {
    if (index >= this.length) {
      return this.append(value);
    }
    if (index < 0) {
      console.log("Insert at valid index!");
      return this.printList();
    }
    if (index == 0) {
      return this.prepend(value);
    }
    const newNode = new Node(value);

    const leader = this.traverseToIndex(index - 1);
    const follower = leader.next;
    leader.next = newNode;
    newNode.prev = leader;
    newNode.next = follower;
    follower.prev = newNode;
    this.length++;
    // console.log(this);
    return this.printList();
  }
  remove(index) {
    if (index < 0 || index == 0) {
      console.log("Give valid index!");
      return this.printList();
    }
    if (index > this.length) {
      console.log("Give valid index!");
      return this.printList();
    }
    const beforeNode = this.traverseToIndex(index - 1);
    const holdingPointer = beforeNode.next;
    beforeNode.next = holdingPointer.next;
    this.length--;
    return this.printList();
  }
  traverseToIndex(index) {
    let counter = 0;
    let currentNode = this.head;

    while (counter != index) {
      currentNode = currentNode.next;
      counter++;
    }
    return currentNode;
  }

  printList() {
    const array = [];
    let currentNode = this.head;
    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }
}

const myList = new DoublyLinkedList(10);

myList.append(5);
myList.append(16);
myList.prepend(1);
myList.insert(99, 300);
myList.insert(99, 2);
myList.insert(100, -5);
// myList.remove(3);
// myList.insert(69, 0);
// myList.remove(99);
