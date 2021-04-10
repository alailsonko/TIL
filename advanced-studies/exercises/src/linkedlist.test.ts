import { inspect } from "util";
function logger(name: string, data: any) {
  console.log(
    `${name}`,
    inspect(data, {
      depth: null,
      showHidden: false,
    })
  );
}
type INode = {
  data: number;
  next: INode;
} | null;

class NodeL {
  data: number;
  next: INode;
  constructor(data: number, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList {
  head: INode;
  constructor() {
    this.head = null;
  }

  insertAtFirst(data: number) {
    this.head = new NodeL(data, this.head);
  }

  insertAtLast(data: number) {
    let node = new NodeL(data);
    let current;
    if (this.head == null) {
      this.insertAtFirst(data);

      return;
    } else {
      current = this.head;
      let num = 5;
      while (current.next) {
        current = current.next;
        current.data = num;
        num++;
      }
      current.next = node;
    }
  }

  readLinkedList() {
    return this.head;
  }
}

describe("Test Linked List", () => {
  const LL = new LinkedList();
  test("should insert node at first", () => {
    LL.insertAtFirst(1);
    const expectedOne = new NodeL(1);
    expect(LL.readLinkedList()).toStrictEqual(expectedOne);

    LL.insertAtFirst(2);
    const expectedTwo = new NodeL(2, expectedOne);
    expect(LL.readLinkedList()).toStrictEqual(expectedTwo);

    LL.insertAtFirst(3);
    const expectedThree = new NodeL(3, expectedTwo);
    expect(LL.readLinkedList()).toStrictEqual(expectedThree);
  });
  test("should insert node at last", () => {
    LL.insertAtLast(4);

    const expectedOne: NodeL = {
      data: 3,
      next: {
        data: 5,
        next: { data: 6, next: { data: 4, next: null } },
      },
    };

    expect(LL.readLinkedList()).toMatchObject(expectedOne);
  });
});
