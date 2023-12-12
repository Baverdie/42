int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	if (!begin_list)
		return (count);
	while (begin_list->next)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}
