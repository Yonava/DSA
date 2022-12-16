
function main() {
  let linkedList = new LinkedList();
  console.log('1 - Push');
  console.log('2 - Pop');
  console.log('3 - Insert');
  console.log('4 - Remove');
  console.log('5 - Is Empty');
  console.log('6 - Get Length');
  console.log('7 - Display List');
  console.log('8 - Exit Program');

  let input = prompt('Select an option: ');
  let value;

  switch (input) {
    case 1:
      value = prompt('enter a value: ');
      console.log(linkedList.push(value))
      break;
    case 2:
      console.log('Item Popped: ' + linkedList.pop());
      break;
    case 3: 
      value = prompt('enter a value: ');
      let index = parseInt(prompt('enter index'));
      linkedList.insertAtIndex(value, index);
  }

}

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.length = 0;
    this.head = null;
    this.tail = null;
  }

  // adds item to the end of the list
  push(value) {
    let newNode = new Node(value);
    if (this.isEmpty()) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;

    return this;
  }

  // removes item from the end of the list
  pop() {

    if (this.isEmpty()) {
      console.log('Nothing to pop! list is empty');
      return;
    }

    let temp = this.head;
    while (temp.next.next) {
      temp = temp.next;
    }
    let removedNode = this.tail;
    this.tail = temp;
    this.length--;

    // if last node gets removed
    if (this.isEmpty()) {
      this.head = null;
      this.tail = null;
    }

    return removedNode;
  }

  // insert an item at a certain index
  insertAtIndex(value, index) {
    if (index > this.length) {
      console.log('insertion out of range');
      return;
    }

    let newNode = new Node(value);
    
    // if linked list is empty
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
      return;
    }

    let temp = this.head;

    for (let i = 0; i < (index - 1); i++) {
      temp = temp.next;
    }

    if (!temp.next) {
      this.tail = newNode;
      newNode.next = null;
    } else {
      newNode.next = temp.next;
    }

    temp.next = newNode;
    this.length++;
  }

  // removes item at certain index
  removeAtIndex(index) {

    if (index > this.length - 1) {
      console.log('removal index out of range');
      return;
    } else if (this.isEmpty()) {
      console.log('linked list is empty');
      return;
    // checks if its the end of the list
    } else if (this.length === 1) {
      this.head = null;
      this.tail = null;
      return;
    }

    let temp = this.head;

    for (let i = 0; i < (index - 1); i++) {
      temp = temp.next;
    }

    // if removing tail
    if (!temp.next.next) {
      this.tail = temp;
      temp.next = null;
    } else {
      temp.next = temp.next.next;
    }

    this.length--;
  }

  isEmpty() {
    return !this.length;
  }

  getLength() {
    return this.length;
  }
}

main();