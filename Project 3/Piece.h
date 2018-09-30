#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

//char chooseRandomPiece();

class Piece
{
public:
	Piece();
	int getFirstX(int Type, int pieceRotation); // gets the initial position of piece
	int getFirstY(int Type, int pieceRotation); // gets the initial y coord of the piece
	int getTetrominoPart(int Type, int pieceRotation, int x, int y); // 
	void choosePieces(int& current, int& next);
private:
	char pieces[10 /*10 different shapes*/][4 /*4 different rotations for each*/][4][4];
};


const int piece[10 /*10 different shapes*/][4 /*4 different rotations for each*/][4 /*4 rows*/][4 /*4 cols*/] 
{
	{ // I
		{ // I orientation 0
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		},
		{ // I orientation 1
			{ 0,1,0,0},
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 }
		},
		{ // I orientation 2
			{ 0,0,0,0 },
			{ 1,1,1,1 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // I orientation 3
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 }
		}
	},
	{ // L
		{ // L orientation 0
			{ 0,0,0,0 },
			{ 1,1,1,0 },
			{ 1,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // L orientation 1
			{ 0,1,1,0 },
			{ 0,0,1,0 },
			{ 0,0,1,0 },
			{ 0,0,0,0 }
		},
		{ // L orientation 2
			{ 0,0,0,0 },
			{ 0,0,1,0 },
			{ 1,1,1,0 },
			{ 0,0,0,0 }
		},
		{ // L orientation 3
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,1,0 }
		}
	},
	{ // J
		{ // J orientation 0
			{ 0,0,0,0 },
			{ 0,1,1,1 },
			{ 0,0,0,1 },
			{ 0,0,0,0 }
		},
		{ // J orientation 1
			{ 0,0,0,0 },
			{ 0,0,1,0 },
			{ 0,0,1,0 },
			{ 0,1,1,0 }
		},
		{ // J orientation 2
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,1,1,1 },
			{ 0,0,0,0 }
		},
		{
			{ 0,1,1,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
	},
	{ // T
		{ // T orientation 0
			{ 0,1,0,0 },
			{ 1,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // T orientation 1
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
		{ // T orientation 2
			{ 0,0,0,0 },
			{ 1,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
		{ // T orientation 3
			{ 0,1,0,0 },
			{ 1,1,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
	},
	{ // O 
		{ // O orientation 0
			{ 1,1,0,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // O orientation 1
			{ 1,1,0,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // O orientation 2
			{ 1,1,0,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // O orientation 3
			{ 1,1,0,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
	},
	{ // S 
		{ // S orientation 0
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 }
		},
		{ // S orientation 1
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,1,0 },
			{ 0,0,0,0 }
		},
		{ // S orientation 2
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 }
		},
		{ // S orientation 3
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,1,0 },
			{ 0,0,0,0 }
		},
	},
	{ // Z
		{ // Z orientation 0
			{ 0,0,0,0 },
			{ 1,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,0,0 }
		},
		{ // Z orientation 1
			{ 0,0,1,0 },
			{ 0,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
		{ // Z orientation 2
			{ 0,0,0,0 },
			{ 1,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,0,0 }
		},
		{ // Z orientation 3
			{ 0,0,1,0 },
			{ 0,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
	},
	{ // vapor
		{ // vapor orientation 0
			{ 0,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // vapor orientation 1
			{ 0,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // vapor orientation 2
			{ 0,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // vapor orientation 3
			{ 0,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		}
	},
	{ // foam
		{ // foam orientation 0
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // foam orientation 1
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // foam orientation 2
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // foam orientation 3
			{ 0,0,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
	},
	{ // crazy shape
		{ // crazy shape orientation 0
			{ 1,0,0,1 },
			{ 0,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ // crazy shape orientation 1
			{ 0,0,0,1 },
			{ 0,0,1,0 },
			{ 0,0,1,0 },
			{ 0,0,0,1 }
		},
		{ // crazy shape orientation 2
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 1,0,0,1 }
		},
		{ // crazy shape orientation 3
			{ 1,0,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 1,0,0,0 }
		}
	}
}; 


#endif // PIECE_INCLUDED
