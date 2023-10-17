# quantsc-hft

## Limit Order Book

The goal of this project is to implement a Limit Order Book in C++. This will
then be used by the research team to simulate executions of trades. If you are
unfamiliar with the concept of Limit Order Books, check out this brief
[video](https://www.youtube.com/watch?v=_0KVAfy49h0) about how they work. 

A great overview of the general idea of what we are implementing can be found
[here](https://www.youtube.com/watch?v=nmYx6tQxtSs).

Currently, the next steps for the project are the following:

*Functions*
- [ ] Basic CRUD(create, read, update, and delete/cancel) operations for the LOB for
    the following order types
    - Limit Buy
    - Limit Sell
    - Market Buy
    - Market Sell
- [ ] Order execution
    - Executing Limit sell
    - Executing Limit buy
    - Executing Market buy
    - Executing Market sell
- [ ] “Best” buy function
- [ ] Num of sell/buys
- [ ] Check if a given order is in the order book
- [ ] Matching algorithm
    - Naive random
    - Price-time-priority algorithm
    - Pro-rata
    - Auction mechanism

