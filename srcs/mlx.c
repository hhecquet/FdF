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
bon debut avec z qui change le reste a gerer
*/

//sqrt(((((data->map[j][i + 1] - data->map[j][i] - data->scale)/2) * sinf((((2 *
//M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data->map[j][i]
//+ data->scale)/2)) * (((data->map[j][i + 1] - data->map[j][i] - data->scale)/2
//) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] -
//data->map[j][i] + data->scale)/2))) - (((((data->map[j][i + 1] - data->map[j][
//i])/2) * sinf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i +
//1] - data->map[j][i])/2))) * ((((data->map[j][i + 1] - data->map[j][i])/2) * s
//inf((((2 * M_PI)/360)*data->angley) + (M_PI/2)) + ((data->map[j][i + 1] - data
//->map[j][i])/2)))))