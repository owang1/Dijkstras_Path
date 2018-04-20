Project 05: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

1. Confirmed
2. Confirmed (use ttp://student01.cse.nd.edu:9777)
3. 

Trial 1:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023996--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450931--------|3.757812--------|
|500-------------|3.322494--------|17.402344-------|
|1000------------|14.930730-------|66.042969-------|

Trial 2:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450930--------|3.757812--------|
|500-------------|3.329493--------|17.398438-------|
|1000------------|14.984721-------|66.058594-------|

Trial 3:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002999--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.300781--------|
|100-------------|0.102983--------|1.800781--------|
|200-------------|0.450931--------|3.753906--------|
|500-------------|3.339492--------|17.402344-------|
|1000------------|14.951726-------|66.058594-------|

Trial 4:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.140625--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.446931--------|3.757812--------|
|500-------------|3.292498--------|17.406250-------|
|1000------------|14.965723-------|66.035156-------|

Trial 5:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023996--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450931--------|3.757812--------|
|500-------------|3.330493--------|17.402344-------|
|1000------------|14.875738-------|66.042969-------|

Average:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.143750--------|
|20--------------|1.143750--------|1.164062--------|
|50--------------|0.023995--------|1.303907--------|
|100-------------|0.102183--------|1.800781--------|
|200-------------|0.450131--------|3.757031--------|
|500-------------|3.322894--------|17.402344-------|
|1000------------|14.941728-------|66.047656-------|
