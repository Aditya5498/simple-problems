Problem Statement (Leet Code 146)
Least Recently Used (LRU) is a common caching strategy. It defines the policy to evict elements from the cache to make room for new elements when the cache is full, meaning it discards the least recently used items first.

Let’s take an example of a cache that has a capacity of 4 elements. We cache elements 1, 2, 3 and 4.

                1 -> 2 -> 3 -> 4

The diagram above represents the cache state after first access of all four elements. We now need to cache another element “5”.

                2 -> 3 -> 4 -> 5

In LRU cache, we evict the least recently used element (in this case “1”) in case a new element needs to be cached. Now “2” is next in line to be evicted if a new element needs to be cached. Let’s see what happens when “2” is accessed again.

                3 -> 4 -> 5 -> 2
Now “3” becomes the next in line to be evicted from the cache.



Solution :-

We use two data structures to implement an LRU Cache. 
1) Queue is implemented using a doubly-linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). The most recently used pages will be near the front end and the least recently used pages will be near the rear end.

2) A Hash with the page number as key and the address of the corresponding queue node as value.
When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue. 
If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. If the queue is full, i.e. all the frames are full, we remove a node from the rear of the queue, and add the new node to the front of the queue.

References :-
-https://www.geeksforgeeks.org/lru-cache-implementation/
-https://www.youtube.com/watch?v=7ABFKPK2hD4
-https://www.youtube.com/watch?v=akFRa58Svug
