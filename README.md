# Evaluating-Intelligent-Strategy
Van Quoc Thinh Vo
I.	Abstract
Acknowledging the benefits of intelligent voting strategies can be extremely beneficial to the voters. Nowadays, there exists a lot of interesting voting systems. However, in this research, we are solely focusing on plurality and approval voting systems. This paper suggests several different approval and plurality voting strategies to be analyzed. It studies how efficient the strategy does by assuming every voter chooses a specific strategy and examines how it will affect the winner if one voter switches to another strategy. Moreover, it also evaluates the satisfaction of the voters after using one of the strategies. As it turns out, the voting strategy that often votes for more than one candidate perform very well. Thus, approval voting strategies, in general, is better than plurality voting strategies.
II.	Introduction
Every voting system can be manipulated by strategic voters, but which voting strategies benefit voters the most, and which voting systems encourage sincere voting the most? In every election, most real voters are more likely to vote sincerely for whom they prefer. However, it will produce a sincere outcome which might not be the best possible outcome for the voter and their favorite candidates. In this research, we are evaluating different voting strategies for two single-winner voting systems: plurality voting and approval voting. We want to find intelligent voting strategies that will tend to produce the best result for a voter based on the current vote totals and the voter’s preferences.
Historically, intelligent voting strategies have been used in many different elections that could significantly change the outcome of the election. One example of such an election is the 1980 United States presidential election, which included three candidates: Democrat Jimmy Carter, Republican Ronald Reagan and Independent John Anderson. According to the summer polls, Ronald Reagan had the highest number of votes (Straffin 1993). Thus, if everyone voted for their favorite candidate, Ronald Reagan would win the election. However, it is not necessary for the voters to vote for their favorite. It might be better for Jimmy Carter and John Anderson’s voters to try different (maybe insincere) voting strategies to keep their least favorite candidates from winning. In this research, we are conducting experiments to analyze different intelligent voting strategies to find out which strategy is most efficient in different situations.
In a normal election between two candidates, it is obvious that election by majority is the most common voting procedure in use. However, when there are three or more candidates and only one is to be elected, there will be a large range of opinion and preference as to how the winner should be decided. According to Jean-Charles de Borda, in an election among three or more candidates, the winner should be the candidate with the largest point total when points are awarded depending on each voter’s relative preferences (Brams, Fishburn 2004). For example, in an election of three candidates, the awards of two points, one point and zero points are made, respectively, to each voter's most-preferred, second-most-preferred and least-preferred candidates. Whoever has the most points at the end of the election is the winner. On the other hand, the Marquis de Condorcet argued that the winner should be the candidate who is preferred by a simple majority of voters to each of the other candidates separately (Brams, Fishburn 2004). Borda’s system is infamously prone to voter manipulation, while Condorcet systems are relatively difficult to manipulate by voting insincerely, but both kinds of voting system require ranked ballots. Instead, we consider two simpler voting systems for multicandidate elections: approval voting and plurality voting.
Approval voting is a simple single-winner voting protocol. Under approval voting, voters are allowed to vote for as many candidates as they wish but cannot cast more than one vote for each candidate (Brams 1975). This means each candidate can only receive one vote from each voter no matter how they rank in the voter’s preference. Voters are not asked to provide their preferences on the candidates. The winner is whoever has the greatest vote total. One of the advantages of approval voting is that it allows voters a larger number of choices in an election. For example, in an election with n candidates, a voter may choose among 2n possible approval ballots. Nonetheless, in this research, we only focus on eight specific approval voting strategies and one parameterized to give an unlimited number of possible strategies. We will analyze which is the best strategy when the voter considers the current vote totals and the voter’s ranked preferences.
Plurality voting is a voting system that allows each voter to only vote for one candidate. The winner is the candidate with the highest number of votes. Therefore, it is common that “a plurality vote that can be expected to maximize a voter’s utility of the eventual outcome often deserts a favorite alternative to vote for another” (LeGrand 2008). Unlike approval voting, plurality voting obliges voters to either choose to vote for their favorites or vote for other candidates to achieve preferable election outcomes. In this research, we only focus on four specific plurality voting strategies.
III.	Experimental Set-up:
a.	Approval Voting Strategies:
The first three approval strategies we will consider effectively ignore the candidates’ current vote totals. One strategy simply recommends that the voter vote only for their favorite candidate. We call this approach strategy F and define it precisely in Figure 1.
Figure 1
•	For each candidate i: 
       Find the voter’s favorite candidate
Vote for the candidate

Another simple strategy which also does not involve the election state implicitly assumes that each candidate has an equal probability of winning the election. It approves the favorite half of the candidates out of the voter’s preferences. This approval voting strategy is called H and is defined clearly in Figure 2.


Figure 2
•	For each candidate i: 
       Vote for candidate i if and only if they are on the favorite half of the voter’s preference

The last simple strategy that does not take the vote totals into consideration votes for every candidate except for the least-favorite one. We call this strategy U and explain it in Figure 3.
Figure 3
•	For each candidate i: 
       Vote for candidate i if and only if they are not the least-favorite one

We also will consider more sophisticated strategies that take into account both the election state and the voter’s preferences. One strategy approves the current leader in the vote totals and every candidate that the voter favors more than the leader. This strategy is known as strategy D and is illustrated in Figure 4.
Figure 4
•	Vote for first place candidate
•	For each candidate i: 
       Vote for candidate i if and only if they are preferred to the current leader

Another strategy is quite similar to strategy D. However, in this case, it only votes for every candidate that the voter likes more than the current leader but not the leader. We call this strategy Q and define it precisely in Figure 5.

Figure 5
•	For each candidate i: 
       Vote for candidate i if and only if they are preferred to the current leader

We will also consider three strategies that look at not just the current leader but also the current second-place candidate. One strategy approves the favorite of the two currently leading candidates plus all candidates preferred to it. This strategy is called T and is explained in Figure 6.
Figure 6
•	For each candidate i: 
       Vote for candidate i if and only if they are preferred to both of the two current leaders

Another strategy approves all candidates preferred to either of the two currently leading candidates. We name this strategy Y and define it clearly in Figure 7. The relationship between strategy Y and strategy T is similar to the relationship between strategy Q and strategy D.
Figure 7
•	For each candidate i: 
       Vote for candidate i if and only if they are preferred to either the first placer or the second placer

Another strategy can be seen as a compromise between strategies T and Y. Basically, it “approves all alternatives preferred to the currently leading alternative, including that leading alternative if preferred to the currently second-place alternative. In other words, it places an approval cutoff next to the current leader on the side of the current second-placer” (LeGrand 2008). This is called strategy A and is explained precisely in Figure 8.
Figure 8
•	For each candidate i: 
       Vote for candidate i if and only if they are preferred to the current leader
•	Vote for first place candidate if it is preferred to the second placer

In addition, we will analyze a strategy recommend as most effective by Warren Smith (Smith 2000); he calls it a moving-average strategy and we call it strategy W. It gives an approval vote to the voter’s favorite of the top two frontrunners and not the other. Then it considers the rest of the candidates in descending order of votes received. The voter approves the candidates for which the voter’s preference is higher than their average preference for the (previously considered) candidates that currently have more votes. Strategy W is not always even weakly sincere: It can recommend approving candidate A and not candidate B even though the voter prefers B to A. All of the other strategies we’re considering so far are weakly sincere in this sense.
In this research, we will also analyze a strategy that acts differently given different parameter inputs; we call this strategy E. We define new parameters x and y for strategy E in order to find new strategies and to figure out which parameter combination would produce the best results for voters. Strategy E works by first adding y to the number of votes of every candidate. It then raises each of those totals to the x power and divide them by the total of the results. The result is an estimate of each candidate’s probability of winning. Then, we are able to calculate the expected value of the election to the voter by multiplying each candidate’s estimated probability of winning by the voter’s preference for that candidate. Strategy E will suggest voters to vote for whichever candidates that have a preference value higher than the expected value of the election. For a simple example of the parameterized voting strategy E with a parameter x as 2 and y as 1, consider an election with three candidates A, B, and C. They currently have 3, 2 and 1 votes respectively. Their preference values are [1, 0, 2].
	Total = (3 + 1) 2 + (2 + 1)2 + (1 + 1)2 = 29
	Expected value = ((3 + 1) 2 / 29) * 1 + ((2 + 1) 2 / 29) * 0 + ((1 + 1) 2 / 29) * 2
			 = 16/29 + 0 + 4/29 = 0.6897
In this example, candidates A and C have higher preference values than the expected value (1 > 0.6897 and 2 > 0.6897). Therefore, strategy E(2, 1) will approve candidates A and C.
b.	Plurality Voting Strategies:
Firstly, we analyze a simple strategy that only takes the voter’s top preference into consideration. It is identical to strategy F in approval voting. It also approves the candidate that is the voter’s favorite. We call this strategy pF and it can be explained clearly in Figure 1.
Another plurality strategy that we are looking into effectively ignores the voter’s preferences. However, it focuses solely on the election state in order to recommend voter to vote for the candidate with the highest number of votes. This strategy is called pD.
We also consider a strategy that involves both the election state and the voter’s preferences. This strategy suggests that the voter vote for the candidate with the highest number of votes among the candidates preferred to the currently leading candidate. We name this strategy pQ.
Lastly, strategy pA only considers the currently leading and second-placed candidates. It approves only the voter’s favorite of them.
c.	Election:
Each simulated election in this research uses a multi-round system. Every candidate starts with a vote total of zero and every voter starts voting an empty ballot. All voters vote in a predetermined order in each round. When a voter votes, they replace their previous ballot. The vote totals are also updated after each voter votes; if multiple candidates share a vote total, the tie is broken by candidate number. The election continues until a certain number of rounds is completed.
For example, an election has three voters and three candidates A, B, and C. The first voter has the preference value of [0, 1, 2], the second voter has the preference value of [0, 2, 1], and the last voter has the preference value of [2, 1, 0]. We assume every voter uses strategy A and the round limit is three. In the first round, the first voter votes for candidates B and C (as recommend by strategy A) so now B has 1 vote, C has 1 vote, and A still has 0 vote. (At this point, B is considered the frontrunner and C is considered to be in second place.) The second voter then votes for B only so now B has 2 votes, C has 1 vote, and A still has 0 votes. The last voter then votes for candidates A and B so B now has 3 votes, A has 1 vote, and C still has 1 vote. The second round starts and, according the current vote total, the first voter votes for B and C and updates their ballot. Now, B has 3 votes, A has 1 vote, and C has 1 vote. The second voter then votes for B only and updates their ballot so now B has 3 votes, A has 1 vote, and C has 1 vote. The last voter votes for only A this round and updates their ballot. Therefore, currently, B has 2 votes, A has 1 vote, and C has 1 vote. Repeat the same process for the third round and none of the voter changes their ballot and the election stops at this round. The election ends, and B has 2 votes, A has 1 vote, and C has 1 vote. B is thus the winner.
Figure 9

d.	Comparison:
In this research, we set a random preference ordering for every voter. Each candidate in the ordering is assigned with a preference point. The higher the point is, the more favored the candidate is by the voter. For example, a voter may have a preference of [1, 0, 2] for candidate A, B, and C respectively. In this case, C is the favorite candidate while B is the least-favored candidate. We ensure that every possible preference ordering is equally likely. Therefore, we can analyze strategies efficiently in several different situations.
In order to find the most efficient strategy, we decided to compare two strategies directly. Basically, we assume every voter would use the same particular voting strategy. After that, each voter, one at a time, will switch their voting strategy to another strategy. We will then study how the switch changes the winner of the election. The same process will be repeated for every other voter. For instance, we will assume all five voters would use strategy A (AAAAA). We will then analyze if it is better for the first voter when they use strategy T (TAAAA) and all other voters use strategy A. The procedure will also be done with second voter (ATAAA), third voter (AATAA), etc. In order to evaluate voting strategies using this approach, we develop a point system for every strategy. Whichever has the highest point will be considered as the better strategy. This point system is called strategy point and is calculated solely based on the current leading candidate and their preference point. The strategy point is conducted in every election. We will decide which strategy is better by adding their strategy points after many different elections. Eventually, if the strategy point is positive, the strategy that everyone uses will be the better strategy. Whereas, the strategy point is negative, the other strategy will be considered to be better. For example, there are three candidates A, B, and C in an election. When every voter uses strategy F (FFFFF), B wins. When the first voter uses strategy T while all other voters use strategy F (TFFFF), the winner changes to A. In this example, the first voter has preferences [1, 0, 2]. Therefore, the strategy point is equal to the preference point of B minus the preference point of A: 0 – 1 = –1. As the strategy point is negative, it seems it is better for the first voter to use strategy T than strategy F when every other voter uses strategy F. However, this is not the final result. We will run the same process for every voter through many elections and add the strategy points together to decide which of the two voting strategies currently being compared is better.
	In addition, we ran another experiment in order to find the strategies that satisfy voters the most when every voter uses the same strategy. We calculate how much the voters like the winner of each election by totaling the preference values for every voter. In order to analyze how much the chosen strategy satisfies the voters, we compare it to the case when the winner of the election is also every voter’s favorite candidate. After many elections, whichever strategy has the highest percentage is the one that satisfies the voters the most.
IV.	Results and Discussion:
In this research, we have come up with strategy E (x, y) that acts differently given different parameter inputs. After running this strategy with a fixed value of y as 1 in 10,000 elections with 20 candidates, 20 voters, and ten rounds, the value of x as 7 seems to be the best strategy E (x, y). As finding best value for x, we run another stimulation to find the best value for y with a fixed value of x as 7. According to the result, it appears that the lower the value of y is, the better the strategy E (x, y) is. In this case, y as 1 is the best value for strategy E (x, y). Thus, x as 7 and y as 1 are the equilibrium for strategy E (x, y).
In this experiment, we tested every mentioned strategy with 20 candidates, 20 voters, and ten rounds in 10,000 different elections. Overall, strategy A looks like the best strategy. According to Figure 11, whenever everyone uses any other strategies apart from A, strategy A seems considerably better than any strategy. Whereas, Figure 10 illustrates that when everyone uses strategy A, only strategy H and strategy E (7, 1) seem better but by a relatively insignificant amount. Among all approval voting strategies, strategy H, T, and Y also produce good results comparing to other voting strategies. Therefore, we can conclude that the best approval strategies often vote for more than one candidate and except for strategy H, all of these three strategies including A consider the current election state especially the two current leading candidates and the voter’s preference. 
				  Figure 10
 
   












 Figure 11
 
Moreover, according to the results, strategy pA is the best plurality voting strategy, while strategy A is the best approval strategy. However, strategy A is much more effective than strategy pA. The same outcome happens with other approval voting strategies and plurality voting strategies which suggests that, in general, strategies that can approve more than one candidate are more effective than strategies that always vote for one candidate; in other words, “bullet” voting is often not a good strategy under approval voting.
Another experiment that we conducted in order to test the satisfaction of the voters after using one of the strategies produced a lot of interesting results. According to Figure 12, generally, strategy E(7, 1) seems to satisfy the voters the most when they all use the same strategy. Whereas, strategy pD is the worst strategy when it comes to making the voters happy with the outcome (because the voters aren’t voting according to their preferences). Among approval voting strategies, apart from strategy E(7, 1), strategy A, W, and H also produce extremely good results. According to these results, almost every approval voting strategy is better than every plurality strategy. Therefore, it is clear that approval voting strategies are much better at fulfilling the voters’ satisfaction comparing to plurality voting strategies and it suggests that changing the voting system from plurality to approval will make the voters happier on average.
We have conducted research analyzing the intelligence of some voting strategies under the approval voting and plurality voting systems. Our results demonstrate that strategies that both consider the election state and the voter’s preferences and often vote for more than one candidate perform very well under approval voting. Strategies that consider the election state and the voter’s preferences also produce better results under plurality voting. Moreover, overall, approval voting strategies accomplish significantly better results than plurality voting strategies.
V.	Future Work:
There are still many interesting voting systems that can be studied in future research. We would like to apply the same approach we used to analyze the approval and plurality voting systems to study other voting systems. It is possible to study how system that awards different number of points to candidates depending on how they are preferred to the voters such as Borda. Moreover, systems that allow voters to vote for or against candidates like Boehm or Venzke would be also interesting to analyze. In addition, it would be exciting to study strategy systems like Dabagh, antiplurality, and Burnitz-Varrentrapp.   
Additionally, there are a lot of experiments that can be done in this research. Since it took a lot of time to conduct experiments with a large number of candidates, voters, and rounds, it would be fascinating to see how different strategies do in a much higher numbers of voters, candidates, and rounds. Moreover, we could try different ways of generating random preferences and different ways of comparing effectiveness of strategies to see how they would affect the result of the experiment. In addition, we could build a strategy with more parameters in order to try a true genetic algorithms approach. Furthermore, it would be interesting if we could compare strategies in different perspectives. We could study which strategies are best for early voters and which are best for later voters. It would also explain if it is better to better to be an early voter or later voter. Otherwise, we could analyze which voting systems have more stable outcomes when voter use best strategies.














Bibliography
•	Philip D. Straffin. Game Theory and Strategy. The Mathematical Association of America, 1993.
•	Rob LeGrand.  Computational Aspects of Approval Voting and Declared-Strategy Voting.  Ph.D. dissertation (WUCSE-2013-43), Department of Computer Science and Engineering, Washington University, St. Louis, Missouri, April 2008.
•	Steven J. Brams. Game Theory and Politics. Dover Publications, Inc, New York University, Mineola, New York, 2004.
•	Steven J. Brams and Peter C. Fishburn. Approval Voting. The American Political Science Review, Sep, 1978, pp. 831-847.
•	Warren D. Smith. Range Voting. December, 2000.






