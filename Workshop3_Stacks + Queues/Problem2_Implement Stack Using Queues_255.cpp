/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Implement Stack using Queues
    Leetcode Problem 225
    https://leetcode.com/problems/implement-stack-using-queues/
*/

class MyStack {
private:
    queue<int> q;
public:
    // Notice how we did not define a constructor. This is because
    // we don't need a constructor to initialize anything, so the
    // default constructor (when no constructor is defined)
    // will do just fine in this case!

    /** Push element x onto stack. */
    void push(int x) {
        // A queue's enqueue and a stack's push is essentially
        // the same thing, so we can just enqueue x into q.
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // We want to get the last-in element and remove it from the queue.
        // We can only remove the first-in element, so to remove the
        // last-in element, we have to remove all elements that came
        // "before" the last-in element.

        // However, we want to save all the elements in the queue except the
        // last-in one, so when we pop those items, we have to add them back
        // into the queue. Note that this maintains the order of the elements.

        int cur;

        // For each element in the queue except the last-in one, we dequeue
        // it from the queue, and then put it back into the queue.
        for(int i = 0; i < q.size() - 1; i++) {
            cur = q.front();
            q.pop();
            q.push(cur);
        }

        // At this point in the algorithm, the last-in element is now
        // the first-in element. Since we have a queue, we can easily
        // remove this element.
        cur = q.front();
        q.pop();

        // Read the directions carefully: Even though the C++ STL stack
        // doesn't return a value, we're asked to return the popped
        // element in this problem!
        return cur;
    }
    
    /** Get the top element. */
    int top() {
        // We could follow a similar algorithm that we used for the
        // pop function, HOWEVER, because the pop function returns
        // the popped element (which is on the top of the stack),
        // we can come up with a simpler algorithm.

        // Pop the last-in element, and save it
        int top = pop();

        // Put the last-in element back into the queue
        // If we imagine our queue as a stack, we put
        // the element at the top of the stack.
        push(top);

        // Essentially, we popped off an element off the
        // top of the stack, and then put it back in
        // where it originally was.
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        // Checking if a queue is empty is essentially the same
        // as checking if a stack is empty, so we can just check
        // if q is empty.
        return q.empty();
    }
};