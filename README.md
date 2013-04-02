recursivereverse
================

recursively reverse a linked list

Recursion isn't hard, it's just not taught correctly.  It's fairly easy to break it down into rules.

And then people memorize how to do stuff, instead of learning it from priniciples.

Take the classic question, recursively reverse a linked list.  

You will see a lot of people making false starts, or trying to reverse the list in some way like they would reverse an array, or even repeatedly walking the list to the end.

But if you understand some simple rules about recursion, it's fairly easy to figure out how to do this on the fly.  And that is so much better then memorization, because you can explain why you are doing things.

first you are reversing, so you're moving backward, which means you calls your function, then do assignments.  If you were doing something moving forwards, like printing in order, you'd print first, then call the function.  

Now we need to worry about the end, and the beginning.  

First, the beginning, which happens after we have recursively walked the list. 

Now, we want to walk to the last node before null, and we need a place to store what we return.  so assuming we have something like this in c  'node * recursivereverse(node * current)' and a node structure with next as the next link (we never touch our data)

our test is
if (current->next)
  node * newbeginning = recursivereverse(current->next);
else
  return current;
//some assignments go here;

return newbeginning; 

Then we just need to figure out the assignments.

Now, people may get tripped up and try to use the new beginning... but then they have to walk it to the end... but the current node already knows the node that comes after it.

so we assign current->next->next = current;  IE the node that was previously after the current node now points to the current node as it's next.  
And that's fine for all the rest of the list, until we get to our original beginning node.  We need to worry about the new end.

Since it's going to the end, we need to point it to NULL, otherwise it will point to it's predecessor, meaning we'll have an infinite loop at the end of the last two nodes.

Easy way to deal with it is to just assign the next of the current node to NULL, for each node. 


so we add to current->next->next = current;
current->next = NULL;

and then you have a reversed linked list.  This makes certain assumptions about the list (like it has at least one node, and isn't circular), so don't just copy this for your interview.

So with some simple rules, I figured out how to reverse a linked list.  But those simple rules aren't taught, or at least, I came up with them for myself after I became a computer science tutor at my college, because I needed people to understand recursion. 

So I guess my point is, it's not that people can or can't understand recursion, it's whether they are taught to think about things in the right way.  

Now to a certain extent, we need to teach people to generalize, but if you teach people a general rule (always worry about the beginning and end of any data structure, and that's important for everything, including memory management and debugging) and a recursion specific rule (call the function first to reverse, call the function after to use the current order), and they can generalize.  

Too often people come to program with the ability to copy code and get it working (and that isn't anything to denigrate, because it's not simple), but lack the understanding of how to think about things.  

