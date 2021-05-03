#include <iostream>
#include <vector>

// constantes globales
const double G = 9.81;
const double DT = 0.01;
const double K = 101.9;

// favorable a la CPU
struct Particle {
    float mass = 0.0;
    float rad = 0.0;
    double y = 0.0;
    double vy = 0.0;
    double fy = 0.0;
    double fpiso = 0.0;
    bool active = true;
} ;

// functions
void timestep(std::vector<Particle> & particles);
void forces(std::vector<Particle> & particles);

int main(int argc, char *argv[]) {
    //Particle points[2];
    // array of structs
    std::vector<Particle> points;
    points.resize(1);
    // initial conditions
    points[0].mass = 1.98;
    points[0].rad = 0.17;
    points[0].y = 2.36;
    points[0].vy = 0.0;

    // temporal evolution
    for (int tstep = 0; tstep < 500; ++tstep){
        forces(points);
        timestep(points);
        std::cout << tstep*DT << "\t"
                  << points[0].y << "\t"
                  << points[0].vy << std::endl; 
        
    }
    
    return 0;
}

void timestep(std::vector<Particle> & particles)
{
    for(auto & body: particles) {
        body.y = body.y + DT*body.vy;
        body.vy = body.vy + DT*(body.fy + body.fpiso)/body.mass;
    }
}

void forces(std::vector<Particle> & particles)
{
    // reset force
    for(auto & body: particles) {
        body.fy = 0.0;
        body.fpiso = 0.0;

    }
    // add gravitationl force
    for(auto & body: particles) {
        double delta = body.rad - body.y;
        body.fy -= body.mass*G;
        if(delta > 0){
            body.fpiso += K*delta;
        }    
    }
}