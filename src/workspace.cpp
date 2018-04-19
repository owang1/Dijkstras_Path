// FIND ADJACENT NEIGHBORS
t.from.first	// Row coordinates
t.fromt.second	// Col coordinates

if (t.from.first - 1 >= 0 && marked.count(pair<int, int>(t.from.first - 1, t.fromt.second)) > 0) {		// Upper neighbor
	continue;
}

if (t.from.first + 1 < row && marked.count(pair<int, int>(t.from.first + 1, t.fromt.second)) > 0) {	// Lower neighbor
	continue;
}

if (t.fromt.second - 1 >= 0 && marked.count(pair<int, int>(t.from.first, t.fromt.second - 1)) > 0) {		// Left neighbor
	continue;
}

if (t.fromt.second + 1 < col && marked.count(pair<int, int>(t.from.first, t.fromt.second + 1)) > 0) {	// Right neighbor
	continue;
}
