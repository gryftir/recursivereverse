recursivereverse
================

skip to [tail recursion](#tail-recursion)

Beginning
---------



I'm going to be talking aboutrecursively reverse a linked list.  IRL you would be more likely, in c at least, to use recursion for more complex data structures such as trees, but a linked list is a good example, and you might get a discussion of it on an interview.

I've rewritten this, to discuss tail recursive functions and a few other things.  The original version  grew out of a comment I made on Hacker News.
[original comment here](https://news.ycombinator.com/item?id=5477498)

Recursion isn't hard, it's just not taught correctly.  It's fairly easy to break it down into rules and patterns, and get people thinking about it.

I see people memorize how to do stuff, instead of learning it from priniciples, and that's just not helpful.

Let's Take the classic question, recursively reverse a linked list.  

You will see a lot of people making false starts, or trying to reverse the list in some way like they would reverse an array, or even repeatedly walking the list to the end. *Yikes*

But if you understand some simple rules about recursion, it's fairly easy to figure out how to do this on the fly.  And that is so much better then memorization, because you can explain why you are doing things.

First you are reversing, so an easy way to use recursion is moving backward, which means you calls your function, then do assignments.  If you were doing something moving forwards, like printing in order, you'd print first, then call the function. Note, I totally break this rule in tail recursion, but the tail recursion is a more complex function.

Next we need to worry about the end, and the beginning.  

Let's start with the beginning, which in this case happens after we have recursively walked the list. We aren't doing anything until after the recursive call. We want to walk to the last node before null, and we need a place to store what we return.  so assuming we have something like this in c  

`NODE * recursivereverse(NODE * current)` 
and a NODE structure with next as the next link (we never touch our data, so you can specify it in any way).

Our test is


    if (current->next) {
        NODE * newbeginning = recursivereverse(current->next);
        else
          return current;
    //some assignments go here;
       return newbeginning; 
    }
Then we just need to figure out the assignments.

Now, people may get tripped up and try to use the new beginning... but then they have to walk it to the end... but the current node already knows the node that comes after it.

so we assign 
    current->next->next = current;  
IE the node that was previously after the current node now points to the current node as it's next.  
And that's fine for all the rest of the list, until we get to our original beginning node.  We need to worry about the new end.

Since it's going to the end, we need to point it to NULL, otherwise it will point to it's predecessor, meaning we'll have an infinite loop at the end of the last two nodes.

Easy way to deal with it is to just assign the next of the current node to NULL, for each node. 


so we add 
    current->next->next = current;
    current->next = NULL;

and then you have a reversed linked list.  This makes certain assumptions about the list (like it has at least one node, and isn't circular), so don't just copy this for your interview.

So with some simple rules, I figured out how to reverse a linked list.  But those simple rules aren't taught, or at least, I came up with them for myself after I became a computer science tutor at my college, because I needed people to understand recursion. 

So I guess my point is, it's not that people can or can't understand recursion, it's whether they are taught to think about things in the right way.  

Now to a certain extent, we need to teach people to generalize, but if you teach people a general rule (always worry about the beginning and end of any data structure, and that's important for everything, including memory management and debugging) and a recursion specific rule (call the function first to reverse, call the function after to use the current order), and they can generalize.  

Too often people come to program with the ability to copy code and get it working (and that isn't anything to denigrate, because it's not simple), but lack the understanding of how to think about things.  

Tail recursion
--------------

okay, now recursion is mostly used to go backward without an explicit stack.  But it's possible to programmatically turn a recursive function, which is potentially memory intensive, into an interative function.  A compiler can do this fairly easily for a specific type of function, a tail recursive function. 
A tail recursive function [wikipedia](https://en.wikipedia.org/wiki/Tail_recursion) is one that has the recursive call in the return statement.  Nothing happens after the recursive call except the final value is passed back.
An example that might be used to count the characters in a c string looks like this: 

    int charcount(char * array, int size) {
        if (*array == '\0')    
            return size;
        return charcount(array + 1, size + 1); 
    }

the recursive call is the last call made.  It's initially called with a size of 0.

Notice that we are using a second parameter, which we initialize to 0.

transformed to an interative call you get:

    int charcount(char * array) {
        int size = 0;
        while (*array != '\0') {
          array++;
          size++;
        }
        return size;
    }
Pretty simple. since we can keep track of the value inside the loop, we don't need a second parameter.
Now, can you create a tail recursive way to reverse a linked list?



    NODE * tailrecursereverse(NODE * current, NODE * append){
      NODE * next;
      if (current == append)
        return current;
      if (current->next == NULL) {
        current->next = append;
        return current;
      }
      next = current->next;
      current->next = append;
      return tailrecursereverse(next, current);
    }

Now, you can make an interative version the same way.

    NODE * interativetail(NODE * current){
    	NODE * next;
    	NODE * append = NULL;
    	if (current == append)
    		return current;
    	while (current->next != NULL) {
    		next = current->next;
    		current->next = append;
    		append = current;
                current = next;
      	}
    	current->next = append;
    	return current;
    }


Copyright Lawrence Siebert 2013.  See COPYING
    

 






