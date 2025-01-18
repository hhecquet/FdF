/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:31:44 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/14 11:09:32 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rotation central
gradian de couleur
enelever le key hook pour les map trop grande

norme
valgrind

vue iso et para bien mais blouqer les rot et gere les zoom et deplacement
vue top (free a changer) bon debut avec z qui change le reste a gerer

modifer mon menu
tout mettre sur sortie 2
et gerer les couleurs dans les fichiers*/


sqrt(((((data->map[j][i + 1] - data->map[j][i] - data->scale)/2) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data->map[j][i] + data->scale)/2)) * (((data->map[j][i + 1] - data->map[j][i] - data->scale)/2) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data->map[j][i] + data->scale)/2))) - (((((data->map[j][i + 1] - data->map[j][i])/2) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data->map[j][i])/2))) * ((((data->map[j][i + 1] - data->map[j][i])/2) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data->map[j][i])/2)))))