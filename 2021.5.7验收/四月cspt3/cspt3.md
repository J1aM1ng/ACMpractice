# TT与可怜的猫



### 问题描述

自从 TT 成为了助教，他就热衷于给同学们解答疑问，于是他就没有时间进行陪他的猫猫玩了，真是一只可怜的小猫。



TT 在同一时间会与很多同学同时用 QQ（TT特供版） 进行答疑，有时 TT **开启**一个新的窗口，开始一个新的答疑对话；有时 TT **关闭**一个窗口，结束一段答疑； 有时，为了及时回答着急的同学，TT会把一个对话窗口设置为**置顶**状态（置顶状态是一种虚拟的状态，窗口的实际位置并不会发生改变）。

你可以将 TT 的聊天窗口想象成一个队列。如果现在没有窗口处于**置顶**状态，那么在队列中位列第一窗口视为在**顶层**，否则处于**置顶**状态的窗口视为在**顶层**。请注意，不可能同时存在两个窗口处于**置顶**状态（也就是说，处于置顶状态的窗口，要么不存在，要么只有一个）。如果当前**置顶**的窗口被关闭了，则剩余队列中第一窗口视为在**顶层**。

TT 为了安抚自己的猫，于是给猫猫看自己的聊天记录解闷，根据猫猫看屏幕中窗口的时间，TT 给每个窗口分配了一个**喜爱度**，TT 认为**喜爱度**越高，猫猫越开心。由于猫猫具有不确定的生物特性，所以所有的**喜爱度**都是**不同**的。

作为 TT 特供版QQ的研发人员，你要负责完成的工作是为软件记录 TT 的操作，形成一个日志系统。日志有固定的记录格式：`OpId #X: MSG.` ，其中 X*X* 是操作的编号，而 `MSG` 是日志的提示信息，需要使用特定的字符串进行替换。

TT 可能会用到的操作如下：

1. **Add u:** TT 打开一个喜爱度为 u的新窗口，若 u不与当前窗口队列中的某个窗口重复，则该新窗口将新建成功，并成为窗口队列中的最后一个窗口。 如果创建成功，则 `MSG` 记录 `success`。 否则， `MSG` 记录 `same likeness `。
2. **Close u:** TT 关掉了一个喜爱度为 u的窗口，如果该窗口存在，则将其关闭，`MSG` 记录 `close u with c`，u表示喜爱度，c*c* 表示该窗口上次打开至今交流的话的数量。若该窗口不存在，则`MSG` 记录`invalid likeness`。
3. **Chat w:** TT 和**顶层**窗口交流了 w句话，如果当前队列中没有窗口，则`MSG` 记录`empty`，否则记录 `success`。
4. **Rotate x:** 将队列中第 x个窗口放在队首，若 x 大于当前队列中窗口数或小于 11 ，则`MSG` 记录`out of range`，否则记录`success`。举个例子，目前队列中有喜爱度为 5,3,2,8 的四个窗口，Rotate 3 之后，会将喜爱度为 2 的第 3 个窗口放在首位，结果为 2,5,3,8。
5. **Prior:** TT 将目前喜爱度最大的窗口放在队首，如果当前队列中没有窗口，则`MSG` 记录`empty`，否则记录 `success`。
6. **Choose u:** TT 将喜爱度为 u的窗口放在队首，如果喜爱度为 u的窗口存在，则`MSG` 记录`success`，否则记录`invalid likeness`。
7. **Top u:** TT 将喜爱度为 u的窗口设定为**置顶**状态，如果喜爱度为 u的窗口存在，则`MSG` 记录`success`，否则记录`invalid likeness`。注意，处于**置顶**状态的窗口最多不超过一个，也就是说，如果在此次设定前已经有处于置顶状态的窗口，则原有**置顶**状态的窗口的**置顶**状态将会消失。（**置顶**只是一种虚拟的状态，原窗口在队列中的位置不会发生变化）
8. **Untop:** TT 取消当前处于**置顶**状态窗口的**置顶**状态。如果当前没有窗口处于**置顶**状态，则`MSG` 记录`no such person`，否则记录`success`。

最后，由于TT要给自己的猫猫树立一个讲文明有礼貌的榜样，所以在上述操作完成后，还要进行若干次操作，这些操作是：与当前队列中所有说过话的窗口说拜拜。`MSG` 记录`Bye u: c`， u表示喜爱度，c 表示该窗口上次打开至今交流的话的数量。即：TT 先和位于**顶层**的窗口说拜拜，然后将其关闭，如果TT没有和当前**顶层**窗口说过话，则直接将其关闭，如此操作下去，直到队列为空。



### 输入格式

第一行包含一个整数 T (T \leq 5)*T*(*T*≤5)，表示数据组数。

对于每组数据，第一行一个 n*n*，表示执行的操作数，其中 0<n\leq 50000<*n*≤5000。接下来 n*n* 行，每行输入一个操作，保证所有输入数据中的整数不大于 10^9109。

### 输出格式

对于每个指定的操作，按照日志的格式，每个操作行。对于最后的非指定操作，同样按照日志的格式，每个操作一行。

### 样例输入

```
1
30
Add 4
Add 3
Chat 4
Add 3
Rotate 2
Chat 5
Prior
Top 3
Choose 4
Rotate 1
Add 2
Close 4
Chat 7
Choose 2
Chat 7
Add 3
Top 2
Add 4
Choose 3
Chat 7
Prior
Top 3
Rotate 1
Rotate 3
Chat 7
Top 4
Add 2
Close 2
Prior
Add 4

```



### 样例输出

```
OpId #1: success.
OpId #2: success.
OpId #3: success.
OpId #4: same likeness.
OpId #5: success.
OpId #6: success.
OpId #7: success.
OpId #8: success.
OpId #9: success.
OpId #10: success.
OpId #11: success.
OpId #12: close 4 with 4.
OpId #13: success.
OpId #14: success.
OpId #15: success.
OpId #16: same likeness.
OpId #17: success.
OpId #18: success.
OpId #19: success.
OpId #20: success.
OpId #21: success.
OpId #22: success.
OpId #23: success.
OpId #24: success.
OpId #25: success.
OpId #26: success.
OpId #27: same likeness.
OpId #28: close 2 with 7.
OpId #29: success.
OpId #30: same likeness.
OpId #31: Bye 3: 26.
```