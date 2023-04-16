close all;
clear;

out = sim("model_wahadlo");

fi0 = out.fi;

m = str2num(get_param("model_wahadlo/Subsystem", "m"));
l = str2num(get_param("model_wahadlo/Subsystem", "l"));

t = 0.01;

for i = 1:length(fi0)
    plot([0 -l*sin(fi0(i))],[0 -l*cos(fi0(i))],'Color','r','LineWidth',2)
    hold on
    plot(-l*sin(fi0(i)), -l*cos(fi0(i)), 'b.','MarkerSize',5*m)
    hold off
    axis([-1.1*l 1.1*l -1.1*l 1.1*l]);
    pause(t);
end
