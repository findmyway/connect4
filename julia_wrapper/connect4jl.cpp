#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"
#include "Solver.hpp"
#include "Position.hpp"
#include "julia.h"

using namespace GameSolver::Connect4;

JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
    mod.add_type<Position>("Position")
        .method("play", [](Position& p, const std::string& s) { return p.play(s); })
        .method("clone", [](Position& p) { Position& p2(p); return p2; })
        .method("play", [](Position& p, int col) {
            if(col < 0 || col >= Position::WIDTH || !p.canPlay(col) || p.isWinningMove(col)) jl_error("invalid col"); // invalid move
            p.playCol(col);
        });
    mod.add_type<Solver>("Solver")
        .method("solve", &Solver::solve)
        .method("load_book", &Solver::loadBook);
}
