# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:23:35 by fstadelw          #+#    #+#              #
#    Updated: 2019/01/28 14:45:42 by cvignal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBX		:=	libmlx.a

LIBX_PATH	?=	.

LIBX_LINK	:= -L $(LIBX_PATH) -lmlx -framework OpenGL -framework Appkit
LIBX_INC	:= -I $(LIBX_PATH) 
ifndef LIB_LINK
LIB_LINK	:=
LIB_INC		:=
endif

LIB_LINK	+= $(LIBX_LINK)
LIB_INC		+= $(LIBX_INC)
