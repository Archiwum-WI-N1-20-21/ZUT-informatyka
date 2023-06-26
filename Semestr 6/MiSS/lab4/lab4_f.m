close all;
clear;

out = sim("lab4.slx");

x = out.x;
y = out.y;

m1 = str2num(get_param("lab4/Subsystem", "m1"));

t = 2^-5;

for i = 1:length(x)
    plot([0 x(i)],[0 y(i)],'Color','r','LineWidth',2)
    hold on
    plot(x(i), y(i), 'b.','MarkerSize',5*m1)
    hold off
    axis([-5,5,-5,5]);
    pause(t);
end