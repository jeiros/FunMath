#!/usr/bin/env Rscript

# Use as: ./sweep.R ex3_extended.csv TitleOfFigure.png

library(ggplot2)


args <- commandArgs(trailingOnly = TRUE)


d1 <- read.csv(args[1])


d2 <- cbind(sapply(d1[1], as.character),
	    d1[,2:4]) # Change the Error values to categorical type
                  # To use with ggplot2 
d2[d2 == 0] <- NA



p <- ggplot(data = d2, aes(x = Step, y = Time, color = Error)) +
	geom_point() + scale_y_log10() + scale_x_log10()
ggsave(args[2], plot = p, dpi = 900)
