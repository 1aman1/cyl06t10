class Stack {

    constructor() {
        this.items = [];
    }

    printUtil() {
        console.log(this.items)
    }

    push(item) {
        this.items.push(item)
    }

    pop() {
        if (!this.empty())
            this.items.pop()
    }

    top() {
        if (!this.empty())
            return this.items[this.items.length - 1]
    }

    empty() {
        return (this.items.length == 0)
    }

}

var stack = new Stack();

stack.push(1);
stack.printUtil()

stack.push(2);
stack.printUtil()

console.log("top", stack.top());

stack.pop();

console.log("top", stack.top());