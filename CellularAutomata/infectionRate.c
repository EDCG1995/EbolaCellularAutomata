//method sets the infection rate according to the neighbours of each cell
float setInfectionRate(int infectedNeighbours, int deceased) { //infection rate starts at 51.5% and increments to 90%

    float infectionRate = 0.;

    switch (infectedNeighbours) {
        case 1:
            infectionRate = 0.515;
            break;
        case 2:
            infectionRate = 0.57;
            break;
        case 3:
            infectionRate = 0.625; 
            break;
        case 4:
            infectionRate = 0.68;
            break;
        case 5:
            infectionRate = 0.735;
            break;
        case 6:
            infectionRate = 0.79;
            break;
        case 7:
            infectionRate = 0.845;
            break;
        case 8:
            infectionRate = 0.9;
            break;
        default:
            infectionRate = 0.0;
    }
    infectionRate += (deceased * 0.05); //the infection rate increases 5% for every deceased neighbour
    return infectionRate;
}
