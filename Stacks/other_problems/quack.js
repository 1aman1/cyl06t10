class Stack {

    constructor() {
        // console.log('inside stack ctor')
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

class Quack {
    constructor() {
        // console.log('inside quack ctor')
        this.stack_1 = new Stack();
        this.stack_2 = new Stack();
        this.stack_3 = new Stack();
    }

    _move(source, target) {
        while (!source.empty()) {
            target.push(source.top())
            source.pop()
        }
    }

    push(item) {
        this.stack_1.push(item)

        this._move(this.stack_2, this.stack_3)
        this.stack_3.push(item)
        this._move(this.stack_3, this.stack_2)
    }

    pop() {
        let popped_item = this.stack_1.top();
        this.stack_1.pop()

        this._move(this.stack_2, this.stack_3)
        this.stack_3.pop()
        this._move(this.stack_3, this.stack_2)

        return popped_item;
    }

    pull() {
        let popped_item = this.stack_2.top()
        this.stack_2.pop();

        this._move(this.stack_1, this.stack_3)
        this.stack_3.pop();
        this._move(this.stack_3, this.stack_1)

        return popped_item;
    }

    printQuack() {
        console.log('stack s1', this.stack_1.top())
        console.log('stack s2', this.stack_2.top())
    }
};

quacko = new Quack();

quacko.push(1)
quacko.push(2)
quacko.printQuack()
quacko.push(3)

console.log("pulled ", quacko.pull())
quacko.printQuack()

console.log("popped ", quacko.pop())
quacko.printQuack()