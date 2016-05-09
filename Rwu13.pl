:-load_files([wumpus1]).

init_agent:-
    writef('Qualquer coisa\n').

restart_agent:-
    init_agent.

run_agent( _, Acao) :-
     Lista = [goforward, turnright, turnleft, shoot, grab, climb],
     random_member(Acao,Lista).
